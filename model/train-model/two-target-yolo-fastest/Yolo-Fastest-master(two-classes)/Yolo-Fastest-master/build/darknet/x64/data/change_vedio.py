# # 把视频变成灰度
# from  moviepy.editor import *
#
# clip = VideoFileClip(r"D:\test\Yolo-Fastest-master6(two-classes)\Yolo-Fastest-master\build\darknet\x64\data\new\cola.mp4")
# clipblackwhite = clip.fx(vfx.blackwhite)
# clipblackwhite.write_videofile(r"D:\test\Yolo-Fastest-master6(two-classes)\Yolo-Fastest-master\build\darknet\x64\data\new\cola1.mp4")




# # 改变视频尺寸
# import cv2
#
# videoCapture = cv2.VideoCapture('new/cola1.mp4')
#
# fps = 25  # 保存视频的帧率
# size = (160, 160)  # 保存视频的大小
#
# videoWriter = cv2.VideoWriter('new/cola2.mp4', cv2.VideoWriter_fourcc('X', 'V', 'I', 'D'), fps, size)
# i = 0
#
# while True:
#     success, frame = videoCapture.read()
#     if success:
#         i += 1
#         if (i >= 1 and i <= 8000):
#             frame = cv2.resize(frame, size)
#             videoWriter.write(frame)
#
#         if (i > 8000):
#             print("success resize")
#             break
#     else:
#         print('end')
#         break





# 把视频拆分成图片
import cv2

vc = cv2.VideoCapture(r'D:\test\Yolo-Fastest-master6(two-classes)\Yolo-Fastest-master\build\darknet\x64\data\new\cola2.mp4')  # 读入视频文件，命名cv
n = 1  # 计数

if vc.isOpened():  # 判断是否正常打开
    rval, frame = vc.read()
else:
    rval = False

timeF = 10  # 视频帧计数间隔频率

i = 0
while rval:  # 循环读取视频帧
    rval, frame = vc.read()
    if (n % timeF == 0):  # 每隔timeF帧进行存储操作
        i += 1
        print(i)
        cv2.imwrite(r'D:\test\Yolo-Fastest-master6(two-classes)\Yolo-Fastest-master\build\darknet\x64\data\new2\{}.jpg'.format(i),
                    frame)  # 存储为图像
    n = n + 1
    cv2.waitKey(1)
vc.release()

