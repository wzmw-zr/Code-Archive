/*************************************************************************
	> File Name: 1.LeetCode834.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月06日 星期二 07时46分01秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

void dfs(int ind, map<int, vector<int>> &mp, vector<int> &check, int &path_len_sum, int dis) {
    check[ind] = 1;
    path_len_sum += dis;
    for (auto &x : mp[ind]) {
        if (check[x]) continue;
        dfs(x, mp, check, path_len_sum, dis + 1);
    }
    check[ind] = 0;
}

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    vector<int> ans(N, 0), check(N, 0);
    map<int, vector<int>> mp;
    for (auto &x : edges) {
        if (!mp.count(x[0])) mp[x[0]] = vector<int>(0);
        mp[x[0]].push_back(x[1]);
        if (!mp.count(x[1])) mp[x[1]] = vector<int>(0);
        mp[x[1]].push_back(x[0]);
    }
    int path_len_sum = 0;
    for (int i = 0; i < N; i++) {
        path_len_sum = 0;
        dfs(i, mp, check, path_len_sum, 0);
        ans[i] = path_len_sum;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges;
    vector<int> edge(2);
    for (int i = 1; i < n; i++) {
        cin >> edge[0] >> edge[1];
        edges.push_back(edge);
    }
    vector<int> ans = sumOfDistancesInTree(n, edges);
    for (auto &x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
