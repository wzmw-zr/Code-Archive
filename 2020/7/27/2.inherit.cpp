/*************************************************************************
	> File Name: 2.inherit.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月27日 星期一 15时09分34秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define P_ADD(obj, a) {\
    cout << #obj"."#a" add = " << &(obj.a) << endl;\
} 

class Animal {
public:
    Animal(string name) : __name(name) {
        cout << "Animal constructor " << this << endl;
    }
    string name() { return this->__name; }

    ~Animal() {
        cout << "Animal destructor " << this << endl;
    }

    int x, y;
    string __name;
};

class Cat : public Animal {
public:
    Cat() : Animal("hello kitty") {
        cout << "Cat constructor " << this << endl;
    }
    void say() {
        cout << "my name is " << this->name() << endl;
    }
    ~Cat() {
        cout << "Cat destructor " << this << endl;
    }
    int z;
};


ostream &operator<<(ostream &out, const Cat &a) {
    out << "<class Cat> " << &a << endl;
    P_ADD(a, x);
    P_ADD(a, y);
    P_ADD(a, __name);
    P_ADD(a, z);
    return out;
}



int main() {
    Animal a("any");
    Cat c;
    c.say();
    cout << sizeof(a) << " " << sizeof(c) << endl;
    cout << c << endl;
    Animal *p = new Cat();
    cout << "Animal * :" << p->name() << endl;
    delete p;
    return 0;
}
