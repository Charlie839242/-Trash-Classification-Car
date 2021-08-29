# ART-Pi人形检测demo

## 简介

本例程使用RT-Thread AI套件[RT-AK](https://github.com/RT-Thread/RT-AK)，转换人形检测（分类）模型，并接入gc0328-camera，实现实时视频人形检测Demo。

## 软件说明

* 关于RT-AK，是基于RT-Thread的一款跨平台AI模型部署框架，详细参考[RT-Thread/RT-AK](https://github.com/RT-Thread/RT-AK)
* 关于ART-Pi[参考](https://github.com/RT-Thread-Studio/sdk-bsp-stm32h750-realthread-artpi)

## 运行
### 编译&下载

编译完成后，将开发板的 ST-Link USB 口与 PC 机连接，然后将固件下载至开发板。

### 运行效果

正常运行后，在串口命令行中输入命令`ai_camera`运行demo，当模型检测到视频中有人出现是，将进行屏幕闪烁，并定格图像。

## 注意事项 

