/*************************************************************************
	> File Name: 4.struct.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月11日 星期六 18时07分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

//#define offset(T, item) (long)(&(((T *)(NULL))->item)) 
#define offset(T, item) ({\
    T temp;\
    (char *)&(temp.item) - (char *)&(temp);\
})

struct Data {
    char a;
    short b;
    char c;
    double d;
};

int main() {
    struct Data d;
    long x = (long) (&(d.a));
    long y = (long) (&(d.b));
    long z = (long) (&(d.c));
    printf("%d\n%d\n%d\n", 0, y - x, z - x);
    printf("%p %p %p\n", &(d.a), &(d.b), &(d.c));
    printf("%lld\n", offset(struct Data, a));
    printf("%lld\n", offset(struct Data, b));
    printf("%lld\n", offset(struct Data, c));
    printf("%lld\n", offset(struct Data, d));
    return 0;
}
