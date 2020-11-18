#!/usr/bin/env python
# coding=utf-8
class People(object):
    def __init__(self, name: str, age: int, sex: str) -> None:
        self.name = name
        self.age = age
        self.sex = sex
        self.__private = 1000

    def Print_Information(self) -> None:
        print(self.name, self.age, self.sex)

    def __del__(self) -> None:
        print("People")

class Student(People):
    def __init__(self, name: str, age: int, sex: str, stu_id: str) -> None:
        super(Student, self).__init__(name, age, sex)
        # People.__init__(self, name, age, sex)
        self.stu_id = stu_id

    def Print_Information(self) -> None:
        super(Student, self).Print_Information()
        print(self.name, self.age, self.sex, self.stu_id)

    def __del__(self) -> None:
        super(Student, self).__del__()
        print("Student")

people = People("Xiao Hong", 30, "female")
people.Print_Information()
print(people.name)
print(people.__private)

#student = Student("Xiao ming", 20, "male", "2020069001")
#student.Print_Information()
