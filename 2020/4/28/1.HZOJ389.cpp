/*************************************************************************
	> File Name: 1.HZOJ389.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月28日 星期二 10时26分01秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
#define MAX_M 100000

int m, n, mmax;
int num[MAX_M + 5];

int GetNum(int mid) {
    int cnt = 1, pre = 0;
    for (int i = 1; i < m; i++) {
        if (num[i] - num[pre] >= mid) {
            cnt++;
            pre = i;
        }
    }
    return cnt;
}

int GetMaxDis(int l, int r) {
    int mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        int cnt = GetNum(mid);
        if (cnt >= n) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
    }
    sort(num, num + m);
    cout << GetMaxDis(1, mmax) << endl;
    return 0;
}
