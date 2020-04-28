/*************************************************************************
	> File Name: 4.HZOJ488.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月28日 星期二 14时22分45秒
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
#include<cmath>
using namespace std;
#define MAX_N 100000

struct Node {
    int x, y;
};

int n, dis, mmin;
Node city[MAX_N + 5];

int Dis(int ind1, int ind2) {
    return abs(city[ind1].x - city[ind2].x) + abs(city[ind1].y - city[ind2].y);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) { 
        cin >> city[i].x >> city[i].y;
        if (i > 1) dis += Dis(i - 1, i);
    }
    int d = dis - Dis(1, 2) - Dis(2, 3) + Dis(1, 3);
    mmin = min(d, dis);
    for (int i = 3; i <= n; i++) {
        d = d - Dis(i - 2, i) + Dis(i - 2, i - 1) - Dis(i, i + 1) + Dis(i - 1, i + 1);
        mmin = min(mmin, d);
    }
    cout << mmin << endl;
    return 0;
}
