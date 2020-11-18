/*************************************************************************
	> File Name: 5.class.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月18日 星期三 18时27分24秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Animal {
    Animal() {
        cout << "Animal constructor" << endl;
    }

    virtual void say() {
        cout << "Animal say" << endl;
    }

    virtual ~Animal() {
        cout << "Animal destructor" << endl;
    }
};

struct Cat : public Animal {
    Cat() {
        cout << "Cat constructor" << endl;
    }   

    void say() override {
        cout << "Cat say : miao miao miao" << endl;
    }

    ~Cat() override {
        cout << "Cat destructor" << endl;
    }
};

int main() {
    Cat *cat = new Cat();
    cat->say();
    Animal *animal = (Animal *) cat;
    animal->say();
    delete animal;
    return 0;
}
