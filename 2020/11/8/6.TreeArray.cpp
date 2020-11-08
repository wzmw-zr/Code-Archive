/*************************************************************************
	> File Name: 6.TreeArray.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月08日 星期日 14时44分15秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define MAX_N 100010

inline int lowbit(int x) { return x & (-x); }

int n, x, y;
int nums[MAX_N + 10];

void build() {
    for (int i = 1; i <= n; i++) {
        if (i + lowbit(i) > n) continue;
        nums[i + lowbit(i)] += nums[i];
    }
}

int getSum(int l, int r) {
    int sum_1 = 0, sum_2 = 0;
    while (l) {
        sum_1 += nums[l];
        l -= lowbit(l);
    }
    while (r) {
        sum_2 += nums[r];
        r -= lowbit(r);
    }
    return sum_2 - sum_1;
} 

void add(int ind, int x) {
    while (ind <= n) {
        nums[ind] += x;
        ind += lowbit(ind);
    }
}

int main() {
    cin >> n; 
    for (int i = 1; i <= n; i++) cin >> nums[i];
    build();
    while (cin >> x >> y) cout << getSum(x, y) << endl;
    return 0;
}
