/*************************************************************************
	> File Name: 1.LeetCode1203.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月12日 星期二 00时07分44秒
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
    int team;
    vector<int> next;
    Node() = default;
    Node(int ind) : ind(ind), in_degree(0), team(-1) {}
};

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    vector<Node> nodes(n);
    vector<int> teams(m, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        nodes[i].ind = i;
        nodes[i].in_degree = 0;
        nodes[i].team = group[i];
        if (group[i] == -1) continue;
        teams[group[i]]++;
    }
    for (int i = 0; i < n; i++) {
        nodes[i].in_degree += beforeItems[i].size();
        for (int &x : beforeItems[i]) nodes[x].next.push_back(i);
    }

    unordered_map<int, vector<int>> mp;
    for (int i = -1; i < m; i++) mp[i] = vector<int>(0);

    auto cmp = [&](int x, int y) {
        return group[x] < group[y];
    };

    queue<int> que;
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
        if (nodes[i].in_degree) continue;
        tmp.push_back(i);
    }
    sort(tmp.begin(), tmp.end(), cmp);
    for (int &x : tmp) que.push(x);
    while (!que.empty()) {
        int ind = que.front();
        que.pop();
        for (int &x : beforeItems[ind]) {
            if (group[x] == -1) continue;
            if (teams[group[x]]) return vector<int>(0);
        }
        ans.push_back(ind);
        if (group[ind] != -1) teams[group[ind]]--;
        for (int &x : nodes[ind].next) {
            if (!(--nodes[x].in_degree)) que.push(x);
        }
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i].in_degree) return vector<int>(0);
    }
    return ans;
}

int main() {
    return 0;
}
