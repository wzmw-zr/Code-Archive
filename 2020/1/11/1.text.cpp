/*************************************************************************
	> File Name: 1.text.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月11日 星期六 16时09分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

#define MAX(a, b) ({\
    __typeof(a) __a = (a);\
    __typeof(b) __b = (b);\
    __a > __b ? __a : __b;\
})

int main() {
    printf("%d\n", MAX(2, 3));
    return 0;
}
