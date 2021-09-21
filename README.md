# **-Trash-Classification-Car**  
### **9月18日更新,已经移植到了树莓派上**
详情请见另一个仓库[Deploy-yolo-fastest-tflite-on-raspberry](https://github.com/Charlie839242/Deploy-yolo-fastest-tflite-on-raspberry)  
  
  
这是一个基于yolo-fastest模型的小车，主控是art-pi开发板，使用了rt thread操作系统。  
**(之后会花点时间移植到到树莓派上)**  
----------------------------------  

该小车能够识别特定种类的垃圾，然后移动到垃圾附近并使用机械臂将其拾取并放置在垃圾筐内。

## **演示效果**    
### **Demo 1**
&emsp;&emsp;**demo1存在一些问题：**  
如小车有时对不准，距离目标过远时容易走偏，车两侧的铝板使小车在旋转时不够稳定等等。  
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/imgs/demo_1.gif)  
### **Demo 2**  
&emsp;&emsp;**demo2对demo1中的问题进行一系列的改进：**  
对于小车对不准的问题，我们采用了在距离目标一定距离时进行第二次PID调整，这样使得小车积累一定误差后能将误差清零。  
对于车身不稳，我们改进了机械结构，采用一个篮子并改变了摄像头和机械臂的位置，已经机械臂的初始状态。  
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/imgs/demo_2.gif)  


## 小车图片：  
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/imgs/car_first_layer.jpg)  

## **使用的硬件**
1. ART-Pi开发板  
2. ART-Pi多媒体扩展版  
3. gc0328摄像头  
4. F407ZGT6开发板  
5. F103C8T6开发板  
6. 小车，机械臂。  
ART-Pi开发板配合ART-Pi多媒体扩展版和gc0328摄像头，可以实时采集图像，并输入yolo fastest模型，得到检测框的相关信息。  
F103C8T6开发板作为下位机，控制机械臂和小车的移动。  
F407ZGT6开发板作为中间媒体，负责接收ART-Pi返回的信息并对其解码，然后将相应的指令发送给F103C8T6，实现机械臂和小车的控制。  

## 工作流程：  
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/imgs/work_flow.png)  
  
    
      
      
### **9月18日更新,已经移植到了树莓派上**
详情请见另一个仓库[Deploy-yolo-fastest-tflite-on-raspberry](https://github.com/Charlie839242/Deploy-yolo-fastest-tflite-on-raspberry)













