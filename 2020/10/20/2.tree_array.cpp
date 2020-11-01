/*************************************************************************
	> File Name: 2.tree_array.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月20日 星期二 16时14分30秒
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
#define MAX_N 1000010

inline int lowbit(int x) { return x & (-x); }

int n;
int nums[MAX_N + 5];
int t[MAX_N + 5];
int op, x, y;

void init() {
    for (int i = 1; i <= n; i++) {
        t[i] += nums[i];
        int j = i + lowbit(i);
        if (j <= n) t[j] += t[i];
    }
}

void add(int x, int y) {
    while (x <= n) {
        t[x] += y;
        x += lowbit(x);
    }
}

int PreSum(int x) {
    int ans = 0;
    while (x >= 1) {
        ans += t[x];
        x -= lowbit(x);
    }
    return ans;
}

int getSum(int x, int y) {
    return PreSum(y) - PreSum(x);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    init();
    while (cin >> op >> x >> y) {
        if (op & 1) add(x, y);
        else cout << getSum(x, y) << endl;
    }
    return 0;
}
