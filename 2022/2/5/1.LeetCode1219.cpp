/*************************************************************************
	> File Name: 1.LeetCode1219.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月05日 星期六 00时10分51秒
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

// TLE

struct Node {
    int x;
    int y;
    int val;
    vector<int> state;

    Node() = default;
    Node(int x, int y, int val, vector<int> &state) : x(x), y(y), val(val), state(state) {}

    bool operator<(const struct Node &that) const {
        return this->val < that.val;
    }

    bool operator==(const struct Node &that) const {
        return this->x == that.x && this->y == that.y && this->val == that.val && this->state == that.state;
    }
};

namespace std {
    template<>
    struct hash<vector<int>> {
        size_t operator()(const vector<int> &vals) const {
            size_t res = 0;
            for (auto val : vals) {
                res ^= hash<int>()(val);
            }
            return res;
        }
    };

    template<>
    struct hash<Node> {
        size_t operator()(const struct Node &node) const {
            size_t x = node.x;
            size_t y = node.y;
            size_t val = node.val;
            size_t state = hash<decltype(node.state)>()(node.state);
            return x ^ y ^ val ^ state;
        }
    };
};

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void print_vector2d(vector<vector<int>> &grid) {
    cout << "[";
    for (auto line : grid) {
        cout << "[";
        for (auto x : line) {
            cout << x << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    priority_queue<Node> que;
    unordered_set<Node> st;
    int mmax = 0;

    vector<int> state;

    for (int i = 0; i < m; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                s |= (1 << j);
            }
        }
        state.push_back(s);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                int val = grid[i][j];
                state[i] ^= (1 << j);
                que.push(Node(i, j, val, state));
                state[i] ^= (1 << j);
            }
        }
    }

    while (!que.empty()) {
        auto temp = que.top();
        que.pop();
        mmax = max(mmax, temp.val);
        // cout << "x = " << temp.x << ", y = " << temp.y << ", val = " << temp.val << endl;
        if (st.count(temp)) {
            continue;
        }
        st.insert(temp);
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y] || !(temp.state[x] & (1 << y))) {
                continue;
            }
            int val = grid[x][y];
            temp.state[x] ^= (1 << y);
            Node node(x, y, temp.val + val, temp.state);
            que.push(node);
            temp.state[x] ^= (1 << y);
        }
    }
    // cout << "===========================" << endl;
    return mmax;
}

int main() {
    return 0;
}
