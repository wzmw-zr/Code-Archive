/*************************************************************************
	> File Name: 3.LeetCode1872.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月29日 星期六 20时10分42秒
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

unordered_map<int, int> mp;

int dfs(vector<int> &pre, int ind, int &n) {
    if (ind > n) return mp[ind] = 0;
    if (ind == n) return mp[ind] = pre[ind];
    if (mp.count(ind)) return mp[ind];
    int dis = INT32_MIN;
    for (int i = ind; i <= n; i++)  
        dis = max(dis, pre[i] - dfs(pre, i + 1, n));
    mp[ind] = dis;
    return dis;
}

int stoneGameVIII(vector<int> &stones) {
    int n = stones.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) 
        pre[i + 1] = pre[i] + stones[i];
    return dfs(pre, 2, n);
}

int main() {
    return 0;
}
