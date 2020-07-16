#!/usr/bin/env python
# coding=utf-8
"""
this is a instance of datetime module
"""

from datetime import datetime

"""get current time"""
now = datetime.now()
print(now)

"""create object of date"""
"""
format:
year, month, day, hour, mintue, second
"""
date_1 = datetime(2015, 7, 16, 11, 50, 40)
print(date_1)

"""
convert time to timestamp
"""
print(now.timestamp())


"""convert date to string"""
print(now.strftime("%Y-%m-%d"))

"""convert string to date"""
date_2 = datetime.strptime("2018-10-20 10-15-40", "%Y-%m-%d %H-%M-%S")
print(type(date_2))
print(date_2)
