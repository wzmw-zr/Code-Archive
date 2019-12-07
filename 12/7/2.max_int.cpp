/*************************************************************************
	> File Name: 2.max_int.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月07日 星期六 16时26分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
using namespace std;


int max_int(int n, ...) {
    va_list arg;
    va_start(arg, n);
    int ans = INT32_MIN; // INT32_MIN等在inttypes.h头文件中
    while (n--) {
        int temp = va_arg(arg, int);
        temp > ans && (ans = temp);// 使用逻辑与，逻辑或等时，需要明确的返回值
    }
    va_end(arg);
    return ans;
}


int main() {
    printf("%d\n", max_int(3, 3, 5, 16));
    printf("%d\n", max_int(3, 3, 5, 16, 21));
    printf("%d\n", max_int(4, 3, 5, 16, 21));
    return 0;
}
