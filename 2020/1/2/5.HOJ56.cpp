/*************************************************************************
	> File Name: 5.HOJ56.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月02日 星期四 17时17分59秒
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
#define max_n 10
using namespace std;

int num[max_n + 5] = {0};

void init(int x) {
    for (int i = 0; i < x; i++) num[i] = i + 1;
}

int main() {
    int x, y;
    cin >> x >> y;
    init(x);
    while (y > 1) {
        next_permutation(num, num + x);
        y--;
    }
    for (int i = 0; i < x; i++) cout << num[i];
    cout << endl;
    return 0;
}
