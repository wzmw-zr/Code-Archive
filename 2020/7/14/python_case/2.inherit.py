#!/usr/bin/env python
# coding=utf-8

class Animal(object):
    def __init__(self, name):
        self.name = name

    def run(self):
        print(f"{self.name} run...")

class Cat(Animal):
    # rewirte ancestor's function
    def __init__(self, name, color):
        # call his ancestor's init function
        super().__init__(name)
        self.color = color

    def show(self):
        print(f"name = {self.name}, color = {self.color}")

class Dog(Animal):
    def run(self):
        print(f"{self.name} run fast")

# create a instance
cat = Cat("miaomiao", "white")
dog = Dog("wangwang")

cat.run()
cat.show()
dog.run()
