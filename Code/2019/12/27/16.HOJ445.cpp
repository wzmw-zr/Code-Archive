/*************************************************************************
	> File Name: 16.HOJ445.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 16时21分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 1000
using namespace std;

int height[max_n + 5] = {0};

int is_val(int x, int n) {
    int left = 0 ,  right = 0;
    for (int i = 1; i < x; i++) {
        if (height[i] > height[x]) left++;
    }
    for (int i = x + 1; i <= n; i++) {
        if (height[i] > height[x]) right++;
    }
    return left == right;
}

int main() {
    int n, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> height[i];
    for (int i = 1; i <= n; i++) {
        if (is_val(i, n)) count++;
    }
    cout << count;
    return 0;
}
