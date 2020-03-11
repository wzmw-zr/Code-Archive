/*************************************************************************
	> File Name: 1.HZOJ83.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月11日 星期三 16时33分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
#define MAX_N 100
#define MAX_M 8
int n, m, num[MAX_N + 1];

int total(int s, int n, int m) {
    if (m == 0) {
        if (n == 0) return 1;
        return 0;
    }
    int ret = 0;
    for (int i = s; i <= n; i++) {
        ret += total(i, n - i, m - 1); 
    }
    return ret;
}

int func(int s, int left_num, int left_cnt) {
    if (left_cnt == 0) {
        if (left_num == 0) return 1;
        return 0;
    }
    int ans = 0;
    for (int i = s; i <= left_num; i++) {
        ans += func(i, left_num - i, left_cnt - 1);
    }
    return ans;
}

int main() {
    cin >> n >> m;
    cout << total(1, n, m) << endl;
    cout << func(1, n, m) << endl;
    return 0;
}
