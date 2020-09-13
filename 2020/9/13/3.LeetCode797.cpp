/*************************************************************************
	> File Name: 3.LeetCode797.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月13日 星期日 11时04分27秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

void print(vector<int> &path) {
    for (auto &x : path) cout << x << " ";
    cout << endl;
}

void dfs(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &path, int ind, int target) {
    if (ind == target) {
        ans.push_back(path);
        return ;
    }
    for (int i = 0; i < graph[ind].size(); i++) {
        path.push_back(graph[ind][i]);
        print(path);
        dfs(graph, ans, path, graph[ind][i], target);
        path.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n = graph.size() - 1;
    vector<vector<int>> ans;
    vector<int> path;
    path.push_back(0);
    dfs(graph, ans, path, 0, n - 1);
    return ans;
}

int main() {
    return 0;
}
