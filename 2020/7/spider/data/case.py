#!/usr/bin/env python
# coding=utf-8

import requests
src = "http://tiebapic.baidu.com/forum/wh%3D90%2C113%3Bcrop%3D0%2C0%2C90%2C90/sign=ae28110223a85edffad9f62a79783812/96beb2fb43166d225d536dc6512309f79052d205.jpg"
response = requests.get(src)

with open("./tieba/images/1.png", "wb") as file:
    file.write(response.content)
