/*************************************************************************
	> File Name: 5.pointer.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月11日 星期六 19时56分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

struct Data { 
    int x, y;
};

int main() {
    struct Data d;
    struct Data *p = &d;
    char *q = ((char *) p) + 8;
    struct Data *r = (struct Data *) q;
    return 0;
}
