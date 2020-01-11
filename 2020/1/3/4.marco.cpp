/*************************************************************************
	> File Name: 4.marco.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月03日 星期五 21时45分56秒
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

#define P(a) ({\
    printf("the value of " #a " is %d\n", a);\
})

#define print(a, b) ({\
    __typeof(a) __a = (a);\
    __typeof(b) __b = (b);\
    printf("the value of "  #a " and " #b " are %d and %d\n", __a, __b);\
})

#define p(a, b) a ## b

#define cast(a, b) ({\
    printf("ab is %d\n", a##b);\
}) 

int main() {
    int x;
    cin >> x;
    P(x);
    int y = x + 1;
    print(x, y);
    int p(m, 1) = 100;
    cast(m, 1);
    return 0;
}
