/*************************************************************************
	> File Name: 2.LeetCode547.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月07日 星期四 00时10分20秒
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

void dfs(vector<vector<int>> &isConnected, vector<bool> &check, int &n, int ind) {
    for (int i = 0; i < n; i++) {
        if (!isConnected[ind][i] || check[i]) continue;
        check[i] = true;
        dfs(isConnected, check, n, i);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size(), ans = 0;
    vector<bool> check(n, false);
    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        check[i] = true;
        ans++;
        dfs(isConnected, check, n, i);
    }
    return ans;
}

int main() {
    return 0;
}
