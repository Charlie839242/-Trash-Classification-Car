import os

import re

filepath = "add1"  # 文件夹路径

delect = "data"  # 要删除的名字字符串

if __name__ == "__main__":

    if not os.path.exists(filepath):
        print("目录不存在!!")

        os._exit(1)

    filenames = os.listdir(filepath)

    print("文件数目为%i" % len(filenames))

    count = 211

    for name in filenames:

        # newname = 'data'+name  # 若想要在名字前面加字符段，可用此语句

        os.rename(filepath + '\\' + name, filepath + '\\' + str (count)+ '.jpg')

        count += 1

        if count % 100 == 0:
            print("第%i个文件已经改名完成" % count)
