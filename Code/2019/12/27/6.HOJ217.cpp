/*************************************************************************
	> File Name: 6.HOJ217.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 14时55分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100000
using namespace std;

int score[max_n + 5] = {0};

int cmp(int a, int b) {
    return a >= b;
}

void solve(int n) {
    int mid;
    if (n * 1.0 / 2 - floor(n * 1.0 / 2) >= 0.5) mid = (int) ceil(n * 1.0 / 2);
    else mid = (int) floor(n * 1.0 / 2);
    int s, cnt = 0;
    for (int i = 1; i <= mid; i++) {
        s = score[i];
        cnt++;
    } 
    for (int i = cnt + 1; i <= n; i++) {
        if (score[i - 1] == score[i]) cnt++;
        else break;
    }
    cout << s << " " << cnt;
}

int main() {
    int n; 
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> score[i];
    sort(score + 1, score + n + 1, cmp);
    solve(n);
    return 0;
}
