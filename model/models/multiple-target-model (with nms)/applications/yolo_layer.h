#ifndef __YOLO_LAYER_H_
#define __YOLO_LAYER_H_
#include <stdint.h>
typedef struct _obj_key{    // the key to the boxes
    float obj;
    int key;
    int class;
}obj_key, *obj_key_t;

typedef struct _yolo_box{   // charateristics of a bbox
    float x;
    float y;
    float w;
    float h;
    float objectness;
    float class_score0;
    float class_score1;
} yolo_box, *yolo_box_t;

typedef struct _sort_box{   // result of the prediction
    yolo_box *box;
    int index;
    int cls;
} sort_box, *sort_box_t;

typedef struct              // nms rules
{
    float threshold;
    float nms_value;
    uint32_t anchor_number;
    uint32_t boxes_number;
    yolo_box *boxes;

} yolo_region_layer, *yolo_region_layer_t;

int find_max(float obj[125]);
float box_iou(yolo_box a, yolo_box b);
int nms_comparator(void *pa, void *pb);
int yolo_decode(float *out_data);
void do_nms_sort(yolo_region_layer* region_layer, yolo_box *boxes);
int yolo_region_layer_init(yolo_region_layer *region_layer, float threshold, int boxes_number, float nms_value, int anchor_number);
    
#endif
