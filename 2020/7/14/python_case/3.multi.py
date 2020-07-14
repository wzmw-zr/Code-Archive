#!/usr/bin/env python
# coding=utf-8

class Animal(object):
    def __init__(self, name):
        self.name = name

    def say(self):
        print(f"{self.name} is an Animal. I can say...")

class Cat(Animal):
    def say(self):
        print(f"{self.name} is a Cat, say miao miao miao")

class Dog(Animal):
    def say(self):
        print(f"{self.name} is a Dog, say wang wang wang")

# function of animal say 
def Animal_say(animal):
    animal.say()

Animal_say(Animal('a'))
Animal_say(Dog('b'))
Animal_say(Cat('c'))
