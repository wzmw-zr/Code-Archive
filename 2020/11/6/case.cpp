/*************************************************************************
	> File Name: case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月06日 星期五 18时57分40秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct Complex {
    int real, img;
	
	Complex() = default;
    Complex(int real, int img) : real(real), img(img) {}

    Complex operator+(Complex &a) const {
		Complex tmp(this->real+a.real,this->img+a.img);
		return tmp;
    }
};

int main() {
    return 0;
}
