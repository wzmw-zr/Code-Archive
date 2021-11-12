/*************************************************************************
	> File Name: 1.LeetCode375.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月12日 星期五 07时59分48秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

using PII = pair<int, int>;

int dfs(int left, int right, map<PII, int> &mp) {
    if (left >= right) return 0;
    PII inter = PII(left, right);
    if (mp.count(inter)) return mp[inter];
    int ans = INT32_MAX;
    for (int i = left; i <= right; i++) {
        int x = dfs(left, i - 1, mp);
        int y = dfs(i + 1, right, mp);
        ans = min(ans, max(x, y) + i);
    }
    mp[inter] = ans;
    return ans;
}

int getMoneyAmount(int n) {
    if (n == 1) return 0;
    map<PII, int> mp;
    int ans = INT32_MAX;
    for (int i = 1; i <= n; i++) {
        int x = dfs(1, i - 1, mp);
        int y = dfs(i + 1, n, mp);
        ans = min(ans, max(x, y) + i);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << getMoneyAmount(n) << endl;
    return 0;
}
