/*************************************************************************
	> File Name: 2.LeetCode851.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月15日 星期三 09时45分46秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct Node {
    int ind;
    vector<int> out;
    int in_deg;

    Node() = default;
    Node(int ind) : ind(ind), out(vector<int>()), in_deg(0) {}
};

vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int n = quiet.size();
    unordered_map<int, Node> graph;
    for (int i = 0; i < n; i++) graph[i] = Node(i);
    for (auto x : richer) {
        graph[x[0]].out.push_back(x[1]);
        graph[x[1]].in_deg++;
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (!graph[i].in_deg) que.push(i);
    }
    vector<int> ans(n);
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        ans[t] = graph[t].ind;
        for (int x : graph[t].out) {
            if (!(--graph[x].in_deg)) que.push(x);
            if (quiet[graph[x].ind] > quiet[graph[t].ind]) graph[x].ind = graph[t].ind;
        }
    }
    return ans;
}

int main() {
    return 0;
}
