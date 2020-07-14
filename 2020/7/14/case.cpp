/*************************************************************************
	> File Name: case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月14日 星期二 19时11分05秒
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

int main() {
    function<double(double)> inc = [](int x) {return 1 + x; };
    return 0;
}
