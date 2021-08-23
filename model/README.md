# 模型部分
## model文件夹中包含了与yolo fastest模型训练相关的文件内容。
部分参考了晨毅大佬的单目标人形检测作品：https://blog.csdn.net/weixin_37598106/article/details/116493674  
  
最终成品结果如下（采用的model/BSP/multiple-target-model (with nms)目录下的工程）：  
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/model/imgs/test.gif)    
该模型在art-pi硬件上推理一次的时间是47ms：  
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/model/imgs/inference_time.gif)  


该文件夹下：  

multiple-target-yolo-fastest文件夹下包括了所有训练单目标检测相关的文件。  
single-target-yolo-fastest文件下包括了所有训练多目标检测相关的文件。  
model-converter文件夹用于将上述两文件夹中得到的 .weights模型转化成 .h5模型和量化后的 .tflite模型。  
models文件夹中包含了训练好的成品权重，以及h5和tflite文件。  
BSP文件夹中包含了将转化后的tflite模型部署到art-pi开发板上的全部工程文件，包括了yolo解码，nms处理等过程。









