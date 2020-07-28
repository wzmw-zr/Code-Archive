/*************************************************************************
	> File Name: 3.inherit_privilige.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月28日 星期二 18时54分31秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Animal {
public: 
    Animal() = default;
    Animal(string name, int age) : __name(name), age(age) {}
    void say() { 
        cout << "my name is : " << this->__name;
        cout << ", my age is : " << this->age << endl;
    }

protected:
    string __name;

private:
    int age;
};

class Cat : public Animal {
public:
    Cat() = delete;
    Cat(string name, int age) : Animal(name, age) {}
};

class Bat : protected Animal {
public:
    Bat() = delete;
    Bat(string name, int age) : Animal(name, age) {}
    void say() {
        this->Animal::say();
        cout << "class Bat : " << __name << endl;
    }
};

int main() {
    Cat a("kitty", 10);
    a.say();
    Bat b("fly", 10);
    b.say();
    return 0;
}
