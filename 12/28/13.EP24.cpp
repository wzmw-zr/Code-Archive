/*************************************************************************
	> File Name: 13.EP24.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 20时14分04秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
using namespace std;

int main() {
    int num[10];
    for (int i = 0; i < 10; i++) num[i] = i;
    int k = 1000000 - 1;
    
    while (k--) {
        next_permutation(num, num + 10);
    } 
    for (int i = 0; i < 10; i++) cout << num[i];
    cout << endl;
    return 0;
}
