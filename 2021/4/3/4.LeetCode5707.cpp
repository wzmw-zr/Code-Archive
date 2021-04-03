/*************************************************************************
	> File Name: 4.LeetCode5707.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月03日 星期六 23时10分41秒
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

void dfs(vector<int> &groups, vector<int> &check, int &batchSize, int cnt, int &n, int sum, int nums, int &ans) {
    if (cnt == n) {
        ans = max(ans, nums);
        return ;
    }
    if (sum % batchSize == 0) nums += 1;
    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        check[i] = 1;
        sum += groups[i];
        dfs(groups, check, batchSize, cnt + 1, n, sum, nums, ans);
        sum -= groups[i];
        check[i] = 0;
    }
}

int maxHappyGroups(int batchSize, vector<int>& groups) {
    int n = groups.size();
    vector<int> check(n, 0);
    int ans = 0;
    dfs(groups, check, batchSize, 0, n, 0, 0, ans);
    return ans;
}

int main() {
    return 0;
}
