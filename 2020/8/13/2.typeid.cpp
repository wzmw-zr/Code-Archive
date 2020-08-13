/*************************************************************************
	> File Name: 2.typeid.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月13日 星期四 10时22分25秒
 ************************************************************************/

#include<iostream>
#include<typeinfo>
using namespace std;

class Case {
public:
    int x;
};

int main() {
    int a = 123;
    Case b;
    typename typeid(a) c = 234;
    cout << typeid(int).name() << endl;
    cout << typeid(double).name() << endl;
    return 0;
}
