/*************************************************************************
	> File Name: 1.LeetCode216.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月11日 星期五 21时51分12秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

void dfs(vector<vector<int>> &ans, int k, vector<int> path, int sum, int start, int n) {
    if (k <= 0) {
        if (sum == n) ans.push_back(path);
        return ;
    }
    if (start >= 10) return ;
    for (int i = start; i <= 9; i++) {
        path.push_back(i);
        dfs(ans, k - 1, path, sum + i, i + 1, n);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    dfs(ans, k, vector<int>(0, 0), 0, 1, n);
    return ans;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<vector<int>> ans = combinationSum3(k, n);
    for (auto &x : ans) {
        cout << "[";
        for (auto &y : x) cout << y << ", ";
        cout << "]" << endl;
    }
    return 0;
}
