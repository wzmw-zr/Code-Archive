/*************************************************************************
	> File Name: 3.LeetCode77.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月09日 星期五 08时57分45秒
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

void dfs(int ind, int n, int k, vector<int> &path, vector<vector<int>> &ans) {
    if (k == 0) {
        ans.push_back(path);
        return ;
    }
    if (ind > n) return ;
    dfs(ind + 1, n, k, path, ans);
    path.push_back(ind);
    dfs(ind + 1, n, k - 1, path, ans);
    path.pop_back();
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> path;
    dfs(1, n, k, path, ans);
    return ans;
}

int main() {
    return 0;
}
