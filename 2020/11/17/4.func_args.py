#!/usr/bin/env python
# coding=utf-8
def show(*args, name: str):
    print(args)
    print(name)

#show(1, 2, 3, 4, 5, 6, name="Trump")

def what_for_lunch(main_food: str="rice", meat: str="pork", vegetable: str="cabbage"):
    print(main_food, meat, vegetable)

order = {"main_food" : "noodle", "meat" : "steak", "vegetable" : "carrot"}
what_for_lunch(**order)
