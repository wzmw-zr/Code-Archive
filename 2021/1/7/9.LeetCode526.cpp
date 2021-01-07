/*************************************************************************
	> File Name: 9.LeetCode526.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月07日 星期四 18时19分53秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

void dfs(int ind, int &n, int &ans, vector<bool> &check) {
    if (ind > n) {
        ans++;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (check[i]) continue;
        if (!(i % ind) || !(ind % i)) {
            check[i] = true;
            dfs(ind + 1, n, ans, check);
            check[i] = false;
        }
    }
}

int countArrangement(int n) {
    vector<bool> check(n + 1, false);
    int ans = 0;
    dfs(1, n, ans, check);
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << countArrangement(n) << endl;
    return 0;
}
