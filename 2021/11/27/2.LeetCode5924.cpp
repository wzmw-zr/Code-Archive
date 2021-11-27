/*************************************************************************
	> File Name: 2.LeetCode5924.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月27日 星期六 22时55分00秒
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

// TLE

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

struct Node {
    int x;
    int y;
    int val;

    Node() = default;
    Node(int x, int y, int val) : x(x), y(y), val(val) {}

    bool operator<(const struct Node &that) const {
        return this->val > that.val;
    }
};


int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    using PII = pair<int, int>;
    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    int m = rowCosts.size(), n = colCosts.size();
    priority_queue<Node> que;
    que.push(Node(startPos[0], startPos[1], 0));
    set<PII> st;
    while (!que.empty()) {
        auto temp = que.top();
        que.pop();
        if (temp.x == homePos[0] && temp.y == homePos[1]) return temp.val;
        PII t = PII(temp.x, temp.y);
        if (st.count(t)) continue;
        st.insert(t);
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (st.count(PII(x, y))) continue;
            int val = temp.val + (dir[i][0] ? rowCosts[x] : colCosts[y]);
            que.push(Node(x, y, val));
        }
    }
    return -1;
}

int main() {
    return 0;
}
