# 模型部分
## model文件夹中包含了与yolo fastest模型训练相关的文件内容。
部分参考了晨毅大佬的单目标人形检测作品：[ART-PI 嵌入式人形检测](https://blog.csdn.net/weixin_37598106/article/details/116493674)  
  
最终成品结果如下（采用的model/BSP/multiple-target-model (with nms)目录下的工程）：  
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/model/imgs/test.gif)    
该模型在art-pi硬件上推理一次的时间是47ms：  
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/model/imgs/inference_time.png)  


## 该文件夹下：  

multiple-target-yolo-fastest文件夹下包括了所有训练单目标检测相关的文件。  
single-target-yolo-fastest文件下包括了所有训练多目标检测相关的文件。  
model-converter文件夹用于将上述两文件夹中得到的 .weights模型转化成 .h5模型和量化后的 .tflite模型。  
models文件夹中包含了训练好的成品权重，以及h5和tflite文件。  
BSP文件夹中包含了将转化后的tflite模型部署到art-pi开发板上的全部工程文件，包括了yolo解码，nms处理等过程。

## 模型简介
该模型的基础是yolo fastest模型，由于该项目垃圾分类小车，所以我们利用yolo fastest模型来识别两种垃圾：塑料瓶和易拉罐。  

由于art-pi只有50mFLOPS，而在官方给出的yolo fastest模型基础之上，将图片输出改成1*160*160* 1后，模型的计算量仍然略微超过50mFLOPs，如下图所示：  
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/model/imgs/0.054BFLOPs.png)  


由于我们还有yolo解码，nms处理等操作要进行，而这些都相当耗费计算量，因此模型尺寸需要进一步裁剪。  

此时有两种选择，一种是继续减小输入图片的尺寸，另一种是修改模型结构来减少模型的FLOPs。  
由于1*160*160* 1在已经比较模糊，例如下图：  a_160_160_img.png
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/model/imgs/a_160_160_img.png)  

所以不宜再减少输入图片尺寸，因此我们选择了修改模型结构，去掉了两个yolo层和若干卷积层，只保留一个yolo层和其他卷积层。在模型修改后，我们的模型的计算量达到0.012BFLOPs:  
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/model/imgs/0.012BFLOPs.png)
此时已经能够较为流畅的在art-pi上运行（一次推理时间是47ms）。  
在我们修改的模型结构上训练50000 epoch后达到较好效果，对于我们自己的测试集，其mAP达到了97.47%。  
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/model/imgs/test_mAP.png)










