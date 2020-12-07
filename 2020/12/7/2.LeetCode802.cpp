/*************************************************************************
	> File Name: 2.LeetCode802.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月07日 星期一 07时49分18秒
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

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> ans;
    unordered_map<int, vector<int>> mp;
    unordered_set<int> st;
    for (int i = 0; i < n; i++) mp[i] = vector<int>(0);
    for (int i = 0; i < n; i++) {
        for (int &x : graph[i]) mp[x].push_back(i);
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (graph[i].size()) continue;
        que.push(i);
    }
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        if (st.count(temp)) continue;
        int flag = 1;
        for (int &x : graph[temp]) {
            if (st.count(x)) continue;
            flag = 0;
        }
        if (!flag) continue;
        ans.push_back(temp);
        st.insert(temp);
        for (int x : mp[temp]) {
            if (st.count(x)) continue;
            que.push(x);
        }
    }
    return ans;
}

int main() {
    return 0;
}
