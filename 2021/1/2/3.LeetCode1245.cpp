/*************************************************************************
	> File Name: 3.LeetCode1245.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月02日 星期六 01时03分03秒
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

void dfs(int ind, vector<vector<int>> &graph, vector<bool> &check, vector<int> &degree, int len, int &max_len, int &ans) {
    if (check[ind]) return ;
    check[ind] = true;
    if (degree[ind] == 1 && len > max_len) max_len = len, ans = ind;
    for (int &x : graph[ind]) dfs(x, graph, check, degree, len + 1, max_len, ans);
}

int treeDiameter(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<int> degree(n, 0);
    vector<bool> check(n, false);
    vector<vector<int>> graph(n, vector<int>(0));
    for (auto &x : edges) {
        degree[x[0]]++, degree[x[1]]++;   
        graph[x[0]].push_back(x[1]);
        graph[x[1]].push_back(x[0]);
    }
    int ind = 0;
    while (ind < n && degree[ind] > 1) ind++;
    int left_max_len = 0, left_end_point = ind;
    dfs(ind, graph, check, degree, 0, left_max_len, left_end_point);
    for (int i = 0; i < n; i++) check[i] = false;
    int right_max_len = 0, right_end_point = left_end_point;
    dfs(right_end_point, graph, check, degree, 0, right_max_len, right_end_point);
    return right_max_len;
}

int main() {
    return 0;
}
