#!/usr/bin/env python
# coding=utf-8
class Student:
    __information__ = "Student class" # 这就是类属性(类变量)，即在方法外面，不加self的变量
    def __init__(self, name: str, id_num: str, sex: str, age: int):
        """
        __init__()是构造函数，定义构造的过程实际上就是实例化的过程
        下面self.name等就是实例变量
        一般我们会将`self.variable_name = variable_name`。
        """
        self.name = name
        self.id_num = id_num
        self.sex = sex
        self.age = age

    def attend_class(self):
        """
        实例方法，默认要传入self参数的
        """
        print("attend_class")
        pass

    def attend_exam(self):
        print("attend_exam")
        pass

    """
    使用staticmethod这个内置装饰器，定义静态方法，静态方法一般是用来直接通过类调用的，虽然通过实例也可以调用，但是最好不要这么做。
    """
    @staticmethod
    def Print_Job():
        print("Student")

student = Student("xiao wang", "202006901", "male", 18) #实例化对象
undergraduate = Student("xiao li", "202006901", "male", 18) #实例化对象
student.attend_class() # 对象调用实例方法，通过域运算符“.”访问实例的方法
student.attend_exam()
Student.Print_Job()
student.Print_Job()
print(id(student.__information__), id(undergraduate.__information__), id(student.__information__))
print(id(Student.Print_Job), id(undergraduate.Print_Job), id(Student.Print_Job))
