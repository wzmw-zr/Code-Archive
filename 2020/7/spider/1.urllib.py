#!/usr/bin/env python
# coding=utf-8

""" instance of usage of urllib module"""

import urllib.request

"""send a request to an URL and get response"""
response = urllib.request.urlopen("http://www.haizeix.com")

""" get content of the response"""
content = response.read().decode('utf-8')

with open("./haizei.html", "w", encoding="utf-8") as file:
    print(content, file=file)

# response head information
print(response.headers)

# response status code
print(response.status)
