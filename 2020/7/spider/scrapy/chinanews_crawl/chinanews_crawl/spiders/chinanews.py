import scrapy
from bs4 import BeautifulSoup
from ..items import FeedItem


class ChinanewsSpider(scrapy.Spider):
    name = 'chinanews'
    allowed_domains = ['chinanews.com']
    start_urls = ['http://chinanews.com/rss/scroll-news.xml']

    def parse(self, response):
        rss = BeautifulSoup(response.body, "html.parser")
        for item in rss.findall("item"):
            feed_item = FeedItem()
            feed_item['title'] = item.title.text
            feed_item['link'] = item.link.text
            feed_item['desc'] = item.description.text
            #feed_item['pub_date'] = item.pubDate.text
            yield feed_item
