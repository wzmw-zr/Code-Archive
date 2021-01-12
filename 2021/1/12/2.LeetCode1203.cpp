/*************************************************************************
	> File Name: 2.LeetCode1203.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月12日 星期二 09时28分19秒
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
    int ind;
    int in_degree;
    vector<int> next;
    Node() : in_degree(0) {}
    Node(int ind) : ind(ind), in_degree(0) {}
};

vector<int> topSort(vector<int> &deg, vector<vector<int>> &graph, vector<int> &items) {
    queue<int> que;
    for (auto &item : items) {
        if (deg[item]) continue;
        que.push(item);
    }
    vector<int> ans;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        ans.push_back(u);
        for (auto &v : graph[u]) {
            if (--deg[v] == 0) que.push(v);
        }
    }
    return ans.size() == items.size() ? ans : vector<int>(0);
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    vector<vector<int>> groupItem(n + m);

    vector<vector<int>> groupGraph(n + m);
    vector<vector<int>> ItemGraph(n);

    vector<int> groupDegree(n + m, 0);
    vector<int> ItemDegree(n, 0);

    int leftId = m;
    vector<int> id;
    for (int i = 0; i < n + m; i++) id.push_back(i);

    for (int i = 0; i < n; i++) {
        if (group[i] == -1) group[i] = leftId++;
        groupItem[group[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        int curGroup = group[i];
        unordered_set<int> st;
        for (auto &item : beforeItems[i]) {
            int beforeGroup = group[item];
            if (beforeGroup == curGroup) {
                ItemDegree[i] += 1;
                ItemGraph[item].push_back(i);
            } else {
                groupDegree[curGroup] += 1;
                groupGraph[beforeGroup].push_back(curGroup);
            }
        }
    }

    vector<int> groupTopSort = topSort(groupDegree, groupGraph, id);
    if (groupTopSort.size() == 0) return vector<int>(0);
    vector<int> ans;
    for (auto &curGroup : groupTopSort) {
        int size = groupItem[curGroup].size();
        if (size == 0) continue;
        vector<int> res = topSort(ItemDegree, ItemGraph, groupItem[curGroup]);
        if (res.size() == 0) return vector<int>(0);
        for (auto &item : res) ans.push_back(item);
    }
    return ans;
}

int main() {
    return 0;
}
