/*************************************************************************
	> File Name: 2.HZOJ394.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月28日 星期二 10时51分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define MAX_N 50000

int l, n, m;
int num[MAX_N + 5];

int GetNum(int mid) {
    int cnt = 0, pre = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (num[i] - num[pre] < mid) {
            cnt++;
        } else {
            pre = i;
        }
    }
    return cnt;
}

int GetMinMaxDis(int l, int r) {
    int mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        int cnt = GetNum(mid);
        if (cnt <= m) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++) cin >> num[i];
    num[n + 1] = l;
    cout << GetMinMaxDis(0, num[n + 1]) << endl;
    return 0;
}
