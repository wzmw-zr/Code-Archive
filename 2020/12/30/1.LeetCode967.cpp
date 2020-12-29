/*************************************************************************
	> File Name: 1.LeetCode967.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月30日 星期三 00时03分49秒
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

void dfs(unordered_set<int> &ans, int num, int n, int k, int ind, string s) {
    if (ind == n) {
        ans.insert(stoi(s));
        return ;
    }
    if (num < 0 || num >= 10) return ;
    dfs(ans, num + k, n, k, ind + 1, s + to_string(num));
    dfs(ans, num - k, n, k, ind + 1, s + to_string(num));
}

vector<int> numsSameConsecDiff(int n, int k) {
    unordered_set<int> ans;
    for (int i = 1; i <= 9; i++) dfs(ans, i, n, k, 0, "");
    vector<int> res;
    for (int x : ans) res.push_back(x);
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    auto ans = numsSameConsecDiff(n, k);
    for (auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
