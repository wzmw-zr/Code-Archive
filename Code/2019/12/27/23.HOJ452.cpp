/*************************************************************************
	> File Name: 23.HOJ452.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 18时12分33秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 10000
using namespace std;

int train[max_n + 5] = {0};

int min(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (train[j] <= train[j + 1]) continue;
            int temp = train[j];
            train[j] = train[j + 1];
            train[j + 1] = temp;
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> train[i];
    cout << min(n);
    return 0;
}
