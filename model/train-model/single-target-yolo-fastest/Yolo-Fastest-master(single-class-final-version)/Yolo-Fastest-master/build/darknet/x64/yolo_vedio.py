import cv2
from darkflow.net.build import TFNet
import numpy as np
import time

option = {
    'model': 'cfg/yolo-fastest-1.1.cfg',
    'load': 'backup/yolo-fastest-1_7000.weights',
    'threshold': 0.3,
    'gpu': 0.7
}

tfnet = TFNet(option)

capture = cv2.VideoCapture('data/new/test.mp4')  # 读取视频
colors = [tuple(255 * np.random.rand(3)) for i in range(10)]  # 随机创建10中颜色，RGB形式
# 当视频打开时，进行处理
while capture.isOpened():
    stime = time.time()  # 计算起始时间
    ret, frame = capture.read()  # 读取每一帧，第一个参数是bool型的ret，其值为True或False，代表有没有读到图片，第二个参数是当前帧图像
    if ret:
        results = tfnet.return_predict(frame)  # 送入网络进行预测
        # 将 colors results 进行打包
        for color, result in zip(colors, results):
            tl = (result['topleft']['x'], result['topleft']['y'])
            br = (result['bottomright']['x'], result['bottomright']['y'])
            label = result['label']
            frame = cv2.rectangle(frame, tl, br, color, 3)
            frame = cv2.putText(frame, label, tl, cv2.FONT_HERSHEY_COMPLEX, 1, color, 1)
        cv2.imshow('frame', frame)  # 显示当前帧
        print('FPS {:.1f}'.format(1 / (time.time() - stime)))  # 计算帧率
        # 按 q 键退出
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        capture.release()
        cv2.destroyAllWindows()
        break