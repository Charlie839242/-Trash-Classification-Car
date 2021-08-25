#include <yolo_layer.h>
#include <math.h>
#include <rtthread.h>
#include <stdlib.h>
#include <math.h>
static int anchor[5][2]=
{
  {13, 37}, {15, 49}, {19, 66}, {23, 85}, {28, 111}
};

static int input_dims[2] ={160,160};

int find_max(float obj[125])
{
    int max = 0;
    for(int i=1; i<125; i++)
    {
        max = obj[max]>obj[i] ? max:i;
    }
    return max;
}



static int nms_comparator(void *pa, void *pb)
{
    sort_box a = *(sort_box *)pa;
    sort_box b = *(sort_box *)pb;
    float class_scorea = a.box[a.index].class_score0>a.box[a.index].class_score1 ? a.box[a.index].class_score0:a.box[a.index].class_score1;
    float class_scoreb = b.box[b.index].class_score0>b.box[b.index].class_score1 ? b.box[b.index].class_score0:b.box[b.index].class_score1;
    float diff = (class_scorea * a.box[a.index].objectness) -
                    (class_scoreb * b.box[b.index].objectness);

    if (diff < 0)
        return 1;
    else if (diff > 0)
        return -1;
    return 0;
}

static float overlap(float x1, float w1, float x2, float w2)
{
    float l1 = x1 - w1/2;
    float l2 = x2 - w2/2;
    float left = l1 > l2 ? l1 : l2;
    float r1 = x1 + w1/2;
    float r2 = x2 + w2/2;
    float right = r1 < r2 ? r1 : r2;

    return right - left;        // return the x-axis overlap distance
}


static float box_intersection(yolo_box a, yolo_box b)
{
    float w = overlap(a.x, a.w, b.x, b.w);
    float h = overlap(a.y, a.h, b.y, b.h);

    if (w < 0 || h < 0)
        return 0;
    return w * h;               // return the intersection area
}

static float box_union(yolo_box a, yolo_box b)
{
    float i = box_intersection(a, b);
    float u = a.w * a.h + b.w * b.h - i;

    return u;                   // return the union area
}

static float box_iou(yolo_box a, yolo_box b)
{
    return box_intersection(a, b) / box_union(a, b);
}

void do_nms_sort(yolo_region_layer* region_layer, yolo_box *boxes)
{

    float nms_value = region_layer->nms_value;
    int boxes_number =  region_layer->boxes_number;
    
    int i, j;
    sort_box *s = rt_malloc(sizeof(sort_box)*boxes_number);
    RT_ASSERT(s);
    for (i = 0; i < boxes_number; ++i)
    {
        s[i].index = i;     // init s
        s[i].box = boxes;   // find different boxes through s[i].box[i]
    }
    // do nms
    qsort(s, boxes_number, sizeof(sort_box), nms_comparator); // sort all boxes from best to worst
    for (i = 0; i < boxes_number; ++i) // traverse all the boxes. if the iou is close to the best box, then delete it.
    {
        if (boxes[s[i].index].objectness == 0)
            continue;
        yolo_box a = boxes[s[i].index];

        for (j = i + 1; j < boxes_number; ++j)
        {
            yolo_box b = boxes[s[j].index];

            if (box_iou(a, b) > nms_value)
                boxes[s[j].index].objectness = 0.0;
        }
    }
    rt_free(s);

}


int yolo_decode(float *out_data)
{
  int j=0,k=0,l=0;
  for(int i=0; i<5*5*5; i++)
  {
    // yolo obtains the relative loaction of the center of prediction to the center of anchor
    float x_tmp = 1 / (1 + exp(-out_data[i*7+0])); // sigmoid decode
    float y_tmp = 1 / (1 + exp(-out_data[i*7+1]));
    float box_x = (x_tmp + k) / 5;                 //
    float box_y = (y_tmp + l) / 5;
    
    float box_w = (exp(out_data[i*7+2])*anchor[j][0])/ input_dims[0];
    float box_h = (exp(out_data[i*7+3])*anchor[j][1])/ input_dims[1];
    
    float objectness = 1 / (1 + exp(-out_data[i*7+4]));
    
    float class_scores0 = 1 / (1 + exp(-out_data[i*7+5]));
    float class_scores1 = 1 / (1 + exp(-out_data[i*7+6]));
   
//    printf("%d %d %d %f %f, %f %f, %f %f\n", j,k,l, box_x, box_y, box_w, box_h, objectness, class_scores);
    
    out_data[i*7+0] = box_x;
    out_data[i*7+1] = box_y;
    out_data[i*7+2] = box_w;
    out_data[i*7+3] = box_h;
    out_data[i*7+4] = objectness;
    out_data[i*7+5] = class_scores0;
    out_data[i*7+6] = class_scores1;

//    // added
//    if(class_scores0 > class_scores1)
//        out_data[i*7+6] = 0;
//    else
//        out_data[i*7+5] = 0;
//    // end add
    
    if(j++>=4)
    {
      j = 0;
      if(k++>=4)
      {
        k = 0;
        if(l++>=4)
        {
          l = 0;
        }
      }
    }
  }
  return 0;
}


int yolo_region_layer_init(yolo_region_layer *region_layer, float threshold, int boxes_number, float nms_value, int anchor_number){
    region_layer->threshold = threshold;
    region_layer->boxes_number = boxes_number;
    region_layer->nms_value = nms_value;
    region_layer->anchor_number = anchor_number;
    
    return 0;
}

