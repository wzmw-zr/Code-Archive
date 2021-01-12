/*************************************************************************
	> File Name: 3.LeetCode1203.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月12日 星期二 13时53分57秒
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

struct Node {
    int degree;
    vector<int> to;
    Node() : degree(0) {}
};

vector<int> topological_sort(vector<Node> &graph, vector<int> &node_set) {
    queue<int> que;
    for (int &x : node_set) {
        if (graph[x].degree) continue;
        que.push(x);
    }
    vector<int> ans;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        ans.push_back(u);
        for (int &v : graph[u].to) {
            if (--graph[v].degree == 0) que.push(v);
        }
    }
    return ans.size() == node_set.size() ? ans : vector<int>(0);
} 

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    int groupCnt = m;
    for (int i = 0; i < n; i++) {
        if (group[i] != -1) continue;
        group[i] = groupCnt++;
    }

    vector<Node> groupGraph(groupCnt);
    vector<Node> itemGraph(n);

    vector<int> id(groupCnt);
    for (int i = 0; i < groupCnt; i++) id[i] = i;

    vector<vector<int>> groupItems(groupCnt);

    for (int i = 0; i < n; i++) {
        int curGroup = group[i];
        groupItems[curGroup].push_back(i);
        for (auto &item : beforeItems[i]) {
            int beforeGroup = group[item];
            if (beforeGroup == curGroup) {
                itemGraph[i].degree++;
                itemGraph[item].to.push_back(i);
            } else {
                groupGraph[curGroup].degree++;
                groupGraph[beforeGroup].to.push_back(curGroup);
            }
        }
    }

    vector<int> group_top_sort = topological_sort(groupGraph, id);
    if (group_top_sort.size() == 0)  return vector<int>(0);
    vector<int> ans;
    for (int &x : group_top_sort) {
        if (groupItems[x].size() == 0) continue;
        auto res = topological_sort(itemGraph, groupItems[x]);
        if (res.size() == 0) return vector<int>(0);
        for (int &y : res) ans.push_back(y);
    }
    return ans;
}

int main() {
    return 0;
}
