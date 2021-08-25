# # #!/usr/bin/env python
# # # -*- coding:utf-8 -*-
# # # Author's_name_is_NIKOLA_SS
# # from PIL import Image
# # import os
# #
# # input_dir = 'faces/'
# # #输入文件夹
# # out_dir = 'gray_faces/'
# # #输出文件夹注意？转义字符使用///在不在其中
# # a = os.listdir( input_dir )
# #
# # for i in a:
# #     I = Image.open( input_dir + i )
# #     L = I.convert( 'L' )
# #     L.save( out_dir + i )#自动重命名/替换
#
#
#
#
#
#

# 得到灰度图
import cv2
import os
def read_path(file_pathname):
    # 遍历该目录下的所有图片文件
    for filename in os.listdir(file_pathname):
        print(filename)
        img = cv2.imread(file_pathname + '/' + filename)
        ####change to gray
        # （下面第一行是将RGB转成单通道灰度图，第二步是将单通道灰度图转成3通道灰度图）
        img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        im = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)
        #####save figure
        cv2.imwrite('add' + "/" + filename, im)
read_path("add")
# print(os.getcwd())



#转换图片尺寸
from PIL import Image
import os.path
import glob
def convertjpg(jpgfile,outdir,width=160,height=160):
    img=Image.open(jpgfile)
    new_img=img.resize((width,height),Image.BILINEAR)
    new_img.save(os.path.join(outdir,os.path.basename(jpgfile)))

for jpgfile in glob.glob("D:/test/dataset/add/*.jpg"):
    convertjpg(jpgfile,"D:/test/dataset/add")



