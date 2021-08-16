/*************************************************************************
	> File Name: 1.LeetCode526.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月16日 星期一 21时24分35秒
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

void dfs(int ind, int &n, vector<bool> &check, int &ans) {
    if (ind > n) {
        ans++;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (check[i]) continue;
        if (!(ind % i) || !(i % ind)) {
            check[i] = true;
            dfs(ind + 1, n, check, ans);
            check[i] = false;
        }
    }
}

int countArrangement(int n) {
    vector<bool> check(n + 1, false);
    int ans = 0;
    dfs(1, n, check, ans);
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << countArrangement(n) << endl;
    return 0;
}
