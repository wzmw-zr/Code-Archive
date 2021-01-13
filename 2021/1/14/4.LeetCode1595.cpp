/*************************************************************************
	> File Name: 4.LeetCode1595.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月14日 星期四 01时30分56秒
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

struct Edge {
    int from;
    int to;
    int cost;
    Edge() = default;
    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
    bool operator<(const struct Edge &a) const {
        return this->cost > a.cost;
    }
};

int connectTwoGroups(vector<vector<int>>& cost) {
    int size_1 = cost.size(), size_2 = cost[0].size();
    vector<bool> left(size_1, false), right(size_2, false);
    priority_queue<Edge> que;
    for (int i = 0; i < size_1; i++) {
        for (int j = 0; j < size_2; j++) que.push(Edge(i, j, cost[i][j]));
    }
    int ans = 0;
    while (!que.empty() && (size_1 || size_2)) {
        Edge temp = que.top();
        que.pop();
        if (left[temp.from] && right[temp.to]) continue;
        ans += temp.cost;
        if (!left[temp.from]) {
            left[temp.from] = true;
            size_1--;
        }
        if (!right[temp.to]) {
            right[temp.to] = true;
            size_2--;
        }
    }
    return ans;
}

int main() {
    return 0;
}
