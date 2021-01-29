/*************************************************************************
	> File Name: 4.LeetCode1102.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月30日 星期六 01时09分08秒
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
    int x, y;
    int val;
    Node() = default;
    Node(int x, int y, int val) : x(x), y(y), val(val) {}
    bool operator<(const struct Node &a) const {
        return this->val < a.val;
    }
};

struct UnionSet {
    int n;
    vector<int> fa;
    UnionSet() = default;
    UnionSet(int n) : n(n), fa(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }
    void merge(int x, int y) {
        int a = get(x);
        int b = get(y);
        if (a == b) return ;
        fa[a] = b;
        n--;
    }
};

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int maximumMinimumPath(vector<vector<int>>& A) {
    int r = A.size(), c = A[0].size();
    UnionSet u(r * c);
    priority_queue<Node> que;
    vector<vector<bool>> check(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) que.push(Node(i, j, A[i][j]));
    }
    int ans = 0;
    while (!que.empty()) {
        Node temp = que.top();
        que.pop();
        check[temp.x][temp.y] = true;
        ans = temp.val;
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 0 || x >= r || y < 0 || y >= c || !check[x][y]) continue;
            u.merge(temp.x * c + temp.y, x * c + y);
        }
        if (u.get(0) == u.get(r * c - 1)) break;
    }
    return ans;
}

int main() {
    return 0;
}
