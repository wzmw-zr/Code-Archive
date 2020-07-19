#!/usr/bin/env python
# coding=utf-8

"""use requests module to send request and bring parameters"""
import requests

url = "https://www.baidu.com"

# send "get" request without parameters
r = requests.get("https://www.baidu.com")
r.encoding = "utf-8"
#print(r.text)

# send "get" request with parameters
r = requests.get(url, params = {"key1" : "value1", "key2" : "value2"})
r.encoding = "utf-8"
print(r.url)
#print(r.text)

# send "post" request with parameters
r = requests.post(url, data = {"key" : "value"})
#print(r.url)
r.encoding = "utf-8"
#print(r.text)
