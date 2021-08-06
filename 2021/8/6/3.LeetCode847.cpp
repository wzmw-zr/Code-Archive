/*************************************************************************
	> File Name: 3.LeetCode847.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月06日 星期五 19时06分44秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
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

struct State {
    int cover;
    int ind;
    int dis;
    State() = default;
    State(int _cover, int _ind, int _dis = 0) : cover(_cover), ind(_ind), dis(_dis) {}
};

int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    int check[(1 << n) + 10][n + 1];
    memset(check, 0, sizeof(check));
    queue<State> que;
    for (int i = 0; i < n; i++) {
        que.push(State(1 << i, i));
        check[1 << i][i] = 1;
    }
    while (!que.empty()) {
        State temp = que.front();
        que.pop();
        if (temp.cover == ((1 << n) - 1)) return temp.dis;
        for (int x : graph[temp.ind]) {
            if (check[temp.cover | (1 << x)][x]) continue;
            check[temp.cover | (1 << x)][x] = 1;
            que.push(State(temp.cover | (1 << x), x, temp.dis + 1));
        }
    }
    return -1;
}

int main() {
    return 0;
}
