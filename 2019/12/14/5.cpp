/*************************************************************************
	> File Name: 5.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月14日 星期六 20时00分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct Data {
    int x, y;
};


int main () {
    struct Data a[2];
    struct Data *p = a;
    a[0].x = 1;
    a[0].y = 2;
    a[1].x = 3;
    a[1].y = 4;
    printf("%d\n", a.x);
   // printf("%d\n", ((*p) + 1).x);
   // printf("%d\n", *(p + 1)->x);
    return 0;
}
