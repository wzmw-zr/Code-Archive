/*************************************************************************
	> File Name: 2.virtual.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月28日 星期二 15时27分54秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class Animal {
public:
    Animal() = default;
    Animal(string name) : name(name) {}
    virtual string tell_me_your_name() { return this->name; }
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
private:
    string name;
};

class Cat : public Animal {
public:   
    Cat() : Animal("cat") {}
    void run() override {
        cout << "I can run with four legs" << endl;
    }
};

class Bat : public Animal {
public:
    Bat() : Animal("bat") {}
    void run() override {
        cout << "I can fly" << endl;
    }
};

int main() {
    Animal a;
    Cat c;
    Bat b;
    a.run();
    c.run();
    b.run();
    Animal *d = &c;
    d->run();
    d = &b;
    d->run();
    return 0;
}
