/*************************************************************************
	> File Name: 5.multi.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月01日 星期六 15时52分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal {
public:
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
};

class Cat : public Animal {
public:
    void run() override {
        cout << "I can run with four legs" << endl;
    }
};

class Dog : public Animal {
public:
    void run() override {
        cout << "I can run with four legs, tail yao" << endl;
    }
};

class Bat : public Animal {
public:
    void run() override {
        cout << "I can fly" << endl;
    }
};

class A {
public:
    int x;
    virtual void say(int x) {
        cout << "Class A : I can say, x = " << x << endl;
    }
    virtual void run1() {
        
    }
};

class B : public A {

};

class Base {
public:
    Base() { 
        cout << "Base constructor" << endl;
        this->x = new int; 
    }
    virtual ~Base() { 
        cout << "Base destructor" << endl;
        delete this->x; 
    }

private:
    int *x;
};

class Base_A : public Base {
public:
    Base_A() {
        cout << "Base_A constructor" << endl;
        this->y = new int;
    }
    ~Base_A() {
        cout << "Base_A destructor" << endl;
        delete this->y;
    }
private:
    int *y;
};

typedef void (*func)(A *, int);

int main() {
    Base *ba = new Base_A();
    delete ba;
    cout << sizeof(A) << endl;
    A temp_a;
    ((func **)(&temp_a))[0][0](&temp_a, 9973);
    Cat a;
    Animal &b = a;
    Animal *c[10];
    for (int i = 0; i < 10; i++) {
        int op = rand() % 3;
        switch (op) {
            case 0: c[i] = new Cat(); break;
            case 1: c[i] = new Dog(); break;
            case 2: c[i] = new Bat(); break;
        }
    }
    for (int i = 0; i < 10; i++) c[i]->run();
    return 0;
}
