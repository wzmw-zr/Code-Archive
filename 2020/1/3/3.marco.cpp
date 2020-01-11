/*************************************************************************
	> File Name: 3.marco.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月03日 星期五 21时14分49秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
using namespace std;

#define MAX(a, b) ({\
    __typeof(a) __a = a;\
    __typeof(b) __b = b;\
    __a > __b ? __a : __b;\
})

#define print(fmt, args) ({\
    printf(fmt, args);\
})

int main() {
    int a, b;
    cin >> a >> b;
    int res = MAX(a, b);
    print("%d\n", res);
    print("%d", a);
    return 0;
}
