#!/usr/bin/env python
# coding=utf-8

import re

str1 = '<a rel="noreferrer" href="/p/3582435386" title="【科比绝伦】科吧你好，安琪还在。" target="_blank" class="j_th_tit ">【科比绝伦】科吧你好，安琪还在。</a>'

str2 = '<a rel="noreferrer" href="/p/6470878284" title="【科比绝伦】What Can I Say" target="_blank" class="j_th_tit ">【科比绝伦】What Can I Say</a>'

pattern = re.compile('<a rel="noreferrer" href="(/p/\d+?)" title="(.+?)" target="_blank" class="j_th_tit ">.*</a>')

url_title = pattern.findall(str1)
print(url_title)

str3 = '<a rel="noreferrer" class="thumbnail vpic_wrap"><img src="https://imgsa.baidu.com/forum/wh%3D159%2C90/sign=14f569c4d4a20cf446c5f6de4330670f/1206ad4bd11373f0cf7581dca00f4bfbfaed04f4.jpg" attr="74295" data-original="https://imgsa.baidu.com/forum/wh%3D159%2C90/sign=14f569c4d4a20cf446c5f6de4330670f/1206ad4bd11373f0cf7581dca00f4bfbfaed04f4.jpg" bpic="https://imgsa.baidu.com/forum/pic/item/1206ad4bd11373f0cf7581dca00f4bfbfaed04f4.jpg" class="threadlist_pic j_m_pic " style="display: inline; width: 159px; height: 90px;"></a>'

img_pattern = re.compile('<a rel="noreferrer" class="thumbnail vpic_wrap"><img src="(.*\.jpg)" attr=".*" data-original=".*" bpic=".*" class=".*".*></a>')
img = img_pattern.findall(str3)
print(img)

str4 = '<a href="//tieba.baidu.com/f?kw=%E7%A7%91%E6%AF%94&amp;ie=utf-8&amp;pn=50" class="next pagination-item ">下一页&gt;</a>'
next_pattern = re.compile('<a href="(.*)" class=".*">.*</a>')
next = next_pattern.findall(str4)
print(next)
