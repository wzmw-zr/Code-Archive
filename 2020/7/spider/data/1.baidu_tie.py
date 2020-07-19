#!/usr/bin/env python
# coding=utf-8

"""
get pictures from baidu forum
"""

import requests
import re

class TiebaSpider(object):
    """tieba spider"""
    def __init__(self):
        """init attributes"""
        self.kw = input("key word : ")
        self.base_url = "https://tieba.baidu.com/f"
        self.page_num = 1
        self.title = "./title.txt"
        self.headers = {
            "User-Agent" : "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.89 Safari/537.36"
        }
        self.image_re = '<li><a rel="noreferrer" class="thumbnail vpic_wrap"><img src="(.*)" attr=".*" data-original=".*" bpic=".*" class="threadlist_pic j_m_pic ".*></a><div class="threadlist_pic_highlight j_m_pic_light"></div></li>'

        self.title_re = '<a rel="noreferrer" href=".*" title="(.*)" target="_blank" class="j_th_tit ">.*</a>'

        self.next_page = '<a href="(.*)" class="next pagination-item ">下一页&gt;</a>'

        self.image_pattern = re.compile(self.image_re)
        self.title_pattern = re.compile(self.title_re)
        self.next_page_pattern = re.compile(self.next_page)

    def parse_text(self, url, params = None):
        """send request and get response"""
        response = requests.get(url, headers = self.headers, params = params)
        response.encoding = "utf-8"
        """return the text message of response"""
        return response.text

    def save_title(self):
        """save title"""
        with open(f"./data/tieba/tieba_{self.kw}.txt", "a+", encoding = "utf-8") as file:
                file.write(self.title)
                file.write("\n")

    def save_img(self, url):
        """save image"""
        content = self.parse_byte(url = url)
        img_path = f"./tieba/images/{url}.jpg"
        with open(img_path, "wb") as file:
            file.write(content)


    def parse_byte(self, url, params = None):
        response = requests.get(url, params = params, headers = self.headers)
        """return the content of the response"""
        return response.content

    def detail(self, url):
        """get detailed information in the page"""
        content = self.parse_text(url = url)
        urls = re.findall('<a rel="noreferrer" class="thumbnail vpic_wrap"><img src="(.*\.jpg)" attr=".*" data-original=".*" bpic=".*" class=".*".*></a>', content)
        for url in urls:
            self.save_img(url = url)


    def page(self, url, content):
        """parse every page"""
        print(f"{self.page_num}th page is spidering...")
        self.page_num += 1
        self.save_title(content)

        pattern = re.compile('<a rel="noreferrer" href="(/p/\d+?)" title="(.+?)" target="_blank" class="j_th_tit ">.*</a>')
        url_title = pattern.findall(content)
        for url, title in url_title:
            self.title = title
            self.detail('https://tieba.baidu.com' + url)
            #save title
            self.save_title()

        self.save_img(url)

        """judge next page"""
        next_url = re.findall(r'<a href="(.*)" class=".*">.*</a>', content)
        if next_url:
            next_url = "https:" + next_url[0]
            content = self.parse_text(url = next_url)
            self.page(content)
        else:
            print(f"spider get {self.page_num} pages total")

    def start(self):
        print("Spider start")
        content = self.parse_text(url = self.base_url, params = {"kw" : self.kw, "ie" : "utf-8", "fr" : "search"})
        self.page(self.base_url, content)


if __name__ == "__main__":
    spider = TiebaSpider()
    spider.start()
