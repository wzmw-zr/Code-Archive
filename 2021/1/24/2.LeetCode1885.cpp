/*************************************************************************
	> File Name: 2.LeetCode1885.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月24日 星期日 00时09分35秒
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

typedef pair<int, int> PII;

bool check(int &x, int &y, vector<PII> &coordinate) {
    for (auto t : coordinate) {
        if (y == t.second || abs(x - t.first) == abs(y - t.second)) return false;
    }
    return true;
}

void dfs(int ind, int &n, vector<PII> &coordinate, vector<string> &mmap, vector<vector<string>> &ans) {
    if (ind == n) {
        ans.push_back(mmap);
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (!check(ind, i, coordinate)) continue;
        mmap[ind][i] = 'Q';
        coordinate.push_back(PII(ind, i));
        dfs(ind + 1, n, coordinate, mmap, ans);
        coordinate.pop_back();
        mmap[ind][i] = '.';
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> mmap;
    string line = "";
    for (int i = 0; i < n; i++) line += ".";
    for (int i = 0; i < n; i++) mmap.push_back(line);
    vector<PII> coordinate;
    dfs(0, n, coordinate, mmap, ans);
    return ans;
}

int main() {
    return 0;
}
