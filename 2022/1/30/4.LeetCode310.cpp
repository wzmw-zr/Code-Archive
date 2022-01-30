/*************************************************************************
	> File Name: 4.LeetCode310.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月30日 星期日 16时02分06秒
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

using PII = pair<int, int>;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> height(n, 1);
    vector<int> check(n, 0);
    vector<unordered_set<int>> graph(n);
    for (auto &&edge : edges) {
        graph[edge[0]].insert(edge[1]); 
        graph[edge[1]].insert(edge[0]);
    }
    queue<PII> que;
    for (int i = 0; i < n; i++) {
        if (graph[i].size() == 1) {
            que.push(PII(i, 1));
        }
    }
    while (!que.empty()) {
        auto [ind, hgt] = que.front();
        que.pop();
        if (check[ind]) {
            continue;
        }
        height[ind] = hgt;
        check[ind] = 1;
        for (int x : graph[ind]) {
            graph[x].erase(ind);
            if (graph[x].size() == 1) {
                que.push(PII(x, hgt + 1));
            }
        }
        graph[ind].clear();
    }

    int mmax = 1;
    for (int x : height) {
        mmax = max(mmax, x);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (height[i] == mmax) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    return 0;
}
