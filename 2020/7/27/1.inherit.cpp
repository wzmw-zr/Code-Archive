/*************************************************************************
	> File Name: 1.inherit.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月27日 星期一 10时49分45秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Animal {
public:
    string name() { return this->__name; }

private:
    string __name;
};

class Cat : public Animal {
public:
    void say() {
        cout << this->name() << endl;
    }
};

int main() {
    return 0;
}
