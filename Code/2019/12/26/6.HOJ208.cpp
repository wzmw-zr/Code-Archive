/*************************************************************************
	> File Name: 6.HOJ208.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 00时03分53秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100
using namespace std;

int score[max_n + 5] = {0};

int cmp(int a, int b) {
    return a > b;
}

void select(int m, int n) {
    int count = 0, s, i, min = 101;
    for (int i = 100 ; i >= 1; i--) {
        count += score[i];
        if (count > n) {
            if (count < min) {
                min = count;
                count -= score[i];
            }
            continue;
        }
        if (count == n) break;
        if (count < n) continue;
    }
    min == 101 && cout << n << endl;
    min < 101 && cout << min << endl;
}

int main() {
    int m, n;
    cin >> m;
    int s;
    for (int i = 1; i <= m; i++) {
        cin >> s;
        score[s]++;
    }
    cin >> n;
    select(m, n);
    return 0;
}
