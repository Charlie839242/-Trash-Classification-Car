# **-Trash-Classification-Car**
这是一个基于yolo-fastest模型的小车，主控是art-pi开发板，使用了rt thread操作系统。  
**(之后会考虑移植到树莓派上)**  
----------------------------------
该小车能够识别特定种类的垃圾，然后移动到垃圾附近并使用机械臂将其拾取并放置在垃圾筐内。

## **演示效果**    
### **Demo 1**
![image](https://github.com/Charlie839242/-Trash-Classification-Car/blob/main/imgs/demo_1.gif)  
### **Demo 2**  


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













