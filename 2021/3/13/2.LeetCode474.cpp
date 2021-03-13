/*************************************************************************
	> File Name: 2.LeetCode474.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月13日 星期六 08时16分44秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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

void dfs(vector<vector<int>> &cnts, int ind, int &len, int m, int n, int cnt, int &ans) {
    if (ind == len || cnts[ind][0] > m || cnts[ind][1] > n) {
        ans = max(ans, cnt);
        return ;
    }
    dfs(cnts, ind + 1, len, m, n, cnt, ans);
    dfs(cnts, ind + 1, len, m - cnts[ind][0], n - cnts[ind][1], cnt + 1, ans);
}

int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    vector<vector<int>> cnts(len, vector<int>(2, 0));
    for (int i = 0; i < len; i++) {
        for (int j = 0; strs[i][j]; j++) cnts[i][strs[i][j] - '0']++;
    }
    int ans = 0;
    dfs(cnts, 0, len, m, n, 0, ans);
    return ans;
}

int main() {
    return 0;
}
