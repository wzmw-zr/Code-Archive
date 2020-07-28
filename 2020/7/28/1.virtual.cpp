/*************************************************************************
	> File Name: 1.virtual.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月28日 星期二 14时29分17秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Animal {
public:
    Animal(const string &name) : __name(name) {}
    virtual void run() {
        cout << "I don't know how can run" << endl;
    }
    ~Animal() {}

private:
    string __name;
};

class Cat : public Animal {
public:
    Cat() : Animal("cat") {}
    void run() override {
        cout << " Cat: I can run with four legs" << endl;
    }
};

class Dog : public Animal {
public:
    Dog() : Animal("dog") {}
    void run() override {
        cout << "Dog: I can also run with four legs" << endl;
    }
};

int main() {
    Cat a;
    Dog d;
    Animal &b = a;
    a.run();
    b.run();
    Animal *c = &a;
    c->run();
    c = &d;
    c->run();
    return 0;
}
