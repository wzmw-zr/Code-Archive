/*************************************************************************
	> File Name: case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月14日 星期二 19时51分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

#define COLOR(str, code) "\033[" #code "m" str "\033[0m"

#define YELLOW(str) COLOR(str, 33) 
#define RED(str) COLOR(str, 31)
#define GREEN(str) COLOR(str, 32)
#define BLUE(str) COLOR(str, 34)

int main() {
    printf(YELLOW("hello world") "\n");
    printf(BLUE("hello haizei") "\n");
    return 0;
}
