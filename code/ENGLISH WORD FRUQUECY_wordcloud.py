import numpy as np
from PIL import Image
import re
from wordcloud import WordCloud, ImageColorGenerator, STOPWORDS
import matplotlib.pyplot as plt
import matplotlib.pyplot as plt
mask= plt.imread('b.jpg')

#准备utf-8编码的文本文件file
fo=open('input.txt', 'r', encoding='utf-8')
strThousand = fo.read().lower()
fo.close()
#print(strThousand)
print("222")
#字符串预处理： #大小写#标点符号#特殊符号
sep = "."
for ch in sep:
    strThousand = strThousand.replace(ch, ' ')
sep = "\""
for ch in sep:
    strThousand = strThousand.replace(ch, ' ')
sep = "\'"
for ch in sep:
    strThousand = strThousand.replace(ch, ' ')
sep = ","
for ch in sep:
    strThousand = strThousand.replace(ch, ' ')
sep = "<"
for ch in sep:
    strThousand = strThousand.replace(ch, ' ')
print("222")
#分解提取单词 list
strList = strThousand.split()
#print(len(strList), strList)
print("222")
#单词计数字典 set , dict
strSet = set(strList)
exclude = {'a', 'the', 'and', 'i', 'you', 'in'}  #排除语法型词汇，代词、冠词、连词等无语义词
strSet = strSet-exclude
print("222")
#print(len(strSet), strSet)
print("222")
strDict = {}
for word in strSet:
    strDict[word] = strList.count(word)

#print(len(strDict), strDict)
wcList = list(strDict.items())
#print(wcList)
print("222")
wcList.sort(key=lambda x: x[1], reverse=True)  #按词频排序 list.sort(key=)
#print(wcList)
print("111")
for i in range(50):      #输出TOP20
    print(wcList[i])
my_wordcloud = WordCloud(scale=4,mask=mask,background_color='white',
                         max_words = 50,max_font_size = 60,random_state=20).generate(wcList)

#显示生成的词云
plt.imshow(my_wordcloud)
plt.axis("off")
plt.show()

#保存生成的图片
my_wordcloud.to_file('result.jpg')