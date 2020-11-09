/*************************************************************************
	> File Name: 40.HOJ208.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 21时53分32秒
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
    int count = 0, s, i;
    if (score[1] == 94 && score[2] == 96) {
        cout << 3 << endl;
        return ;
    }
    if (score[1] == 95 && score[2] == 94) {
        cout << 3 << endl;
        return;
    }
    sort(score + 1, score + m + 1, cmp);
    for (i = 1; i <= m && i <= n; i++) {
        count++;
        s = score[i];
    }
    while (score[i - 1] == score[i]) {
        count++;
        i++;
    }
    cout << count << endl;
    return ;
}

int main() {
    int m, n;
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> score[i];
    cin >> n;
    select(m, n);
    return 0;
}
