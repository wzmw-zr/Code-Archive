#!/usr/bin/env python
# coding=utf-8

import re
import requests
import random

# pc端的user-agent
user_agent_pc = [
    # 谷歌
    'Mozilla/5.0.html (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.html.2171.71 Safari/537.36',
    'Mozilla/5.0.html (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.html.1271.64 Safari/537.11',
    'Mozilla/5.0.html (Windows; U; Windows NT 6.1; en-US) AppleWebKit/534.16 (KHTML, like Gecko) Chrome/10.0.html.648.133 Safari/534.16',
    # 火狐
    'Mozilla/5.0.html (Windows NT 6.1; WOW64; rv:34.0.html) Gecko/20100101 Firefox/34.0.html',
    'Mozilla/5.0.html (X11; U; Linux x86_64; zh-CN; rv:1.9.2.10) Gecko/20100922 Ubuntu/10.10 (maverick) Firefox/3.6.10',
    # opera
    'Mozilla/5.0.html (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.html.2171.95 Safari/537.36 OPR/26.0.html.1656.60',
    # qq浏览器
    'Mozilla/5.0.html (compatible; MSIE 9.0.html; Windows NT 6.1; WOW64; Trident/5.0.html; SLCC2; .NET CLR 2.0.html.50727; .NET CLR 3.5.30729; .NET CLR 3.0.html.30729; Media Center PC 6.0.html; .NET4.0C; .NET4.0E; QQBrowser/7.0.html.3698.400)',
    # 搜狗浏览器
    'Mozilla/5.0.html (Windows NT 5.1) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.html.963.84 Safari/535.11 SE 2.X MetaSr 1.0.html',
    # 360浏览器
    'Mozilla/5.0.html (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/30.0.html.1599.101 Safari/537.36',
    'Mozilla/5.0.html (Windows NT 6.1; WOW64; Trident/7.0.html; rv:11.0.html) like Gecko',
    # uc浏览器
    'Mozilla/5.0.html (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/38.0.html.2125.122 UBrowser/4.0.html.3214.0.html Safari/537.36',
]
# 移动端的user-agent
user_agent_phone = [
    # IPhone
    'Mozilla/5.0.html (iPhone; U; CPU iPhone OS 4_3_3 like Mac OS X; en-us) AppleWebKit/533.17.9 (KHTML, like Gecko) Version/5.0.html.2 Mobile/8J2 Safari/6533.18.5',
    # IPAD
    'Mozilla/5.0.html (iPad; U; CPU OS 4_2_1 like Mac OS X; zh-cn) AppleWebKit/533.17.9 (KHTML, like Gecko) Version/5.0.html.2 Mobile/8C148 Safari/6533.18.5',
    'Mozilla/5.0.html (iPad; U; CPU OS 4_3_3 like Mac OS X; en-us) AppleWebKit/533.17.9 (KHTML, like Gecko) Version/5.0.html.2 Mobile/8J2 Safari/6533.18.5',
    # Android
    'Mozilla/5.0.html (Linux; U; Android 2.2.1; zh-cn; HTC_Wildfire_A3333 Build/FRG83D) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0.html Mobile Safari/533.1',
    'Mozilla/5.0.html (Linux; U; Android 2.3.7; en-us; Nexus One Build/FRF91) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0.html Mobile Safari/533.1',
    # QQ浏览器 Android版本
    'MQQBrowser/26 Mozilla/5.0.html (Linux; U; Android 2.3.7; zh-cn; MB200 Build/GRJ22; CyanogenMod-7) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0.html Mobile Safari/533.1',
    # Android Opera Mobile
    'Opera/9.80 (Android 2.3.4; Linux; Opera Mobi/build-1107180945; U; en-GB) Presto/2.8.149 Version/11.10',
    # Android Pad Moto Xoom
    'Mozilla/5.0.html (Linux; U; Android 3.0.html; en-us; Xoom Build/HRI39) AppleWebKit/534.13 (KHTML, like Gecko) Version/4.0.html Safari/534.13',
]

def get_user_agent_pc():
    return random.choice(user_agent_pc)

def get_user_agent_phone():
    return random.choice(user_agent_phone)

img_pattern_string = '<li><a rel="noreferrer" href="(.*)" .*>.*class="threadlist_pic j_m_pic ".*</a>.*</li>'

title_pattern_string = '<a rel="noreferrer" href=".*" title="(.*)" target="_blank".*</a>'

next_page_pattern_string = '<a href="(.*)".*尾页</a>'

img_pattern = re.compile(img_pattern_string)
title_pattern = re.compile(title_pattern_string)
next_page_pattern = re.compile(next_page_pattern_string)

url="https://tieba.baidu.com/f?ie=utf-8&kw=%E7%A7%91%E6%AF%94&fr=search"
headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.103 Safari/537.36'}

"""
<li><a rel="noreferrer" class="thumbnail vpic_wrap"><img src="http://tiebapic.baidu.com/forum/wh%3D90%2C160%3Bcrop%3D0%2C0%2C90%2C90/sign=4a7c0db3862397ddd62c900d69ae8381/b0c8a9773912b31b9f15f97d9118367adab4e12a.jpg" attr="40974" data-original="http://tiebapic.baidu.com/forum/wh%3D90%2C160%3Bcrop%3D0%2C0%2C90%2C90/sign=4a7c0db3862397ddd62c900d69ae8381/b0c8a9773912b31b9f15f97d9118367adab4e12a.jpg" bpic="http://tiebapic.baidu.com/forum/pic/item/b0c8a9773912b31b9f15f97d9118367adab4e12a.jpg" class="threadlist_pic j_m_pic " style="display: inline; width: 90px; height: 90px;"></a><div class="threadlist_pic_highlight j_m_pic_light"></div></li>
"""

response = requests.get(url, headers={
    'User-Agent' : get_user_agent_pc()
})
response.encoding = "utf-8"
print(response.text)

#print(re.findall(title_pattern, response.text))
print(re.findall(img_pattern, response.text))

def get_page(url):
    try:
        r = requests.get(url)
        r.encoding = "utf-8"
        return r.text
    except:
        return "ERROR"
