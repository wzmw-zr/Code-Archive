/*************************************************************************
	> File Name: 3.LeetCode427.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月14日 星期四 00时54分06秒
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
    bool val;
    bool is_leaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() : val(false), is_leaf(false), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
    Node(bool val, bool is_leaf) : val(val), is_leaf(is_leaf), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
    Node(bool val, bool is_leaf, Node *topLeft, Node *topRight, Node *bottomLeft, Node *bottomRight) : val(val), is_leaf(is_leaf), topLeft(topLeft), topRight(topRight), bottomLeft(bottomLeft), bottomRight(bottomRight) {}
};

Node *construct(vector<vector<int>> &grid, int x, int y, int len) {
    if (len == 1) return new Node(grid[x][y], true);
    Node *topLeft = construct(grid, x, y, len / 2);
    Node *topRight = construct(grid, x, y + len / 2, len / 2);
    Node *bottomLeft = construct(grid, x + len / 2, y, len / 2);
    Node *bottomRight = construct(grid, x + len / 2, y + len / 2, len / 2);
    if (!topLeft->is_leaf || !topRight->is_leaf || !bottomLeft->is_leaf || !bottomRight->is_leaf) {
        Node *ans = new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
        return ans;
    }
    if (topLeft->val && topRight->val && bottomLeft->val && bottomRight->val) {
        Node *ans = new Node(true, true);
        delete topLeft;
        delete topRight;
        delete bottomLeft;
        delete bottomRight;
        return ans;
    }
    if (!topLeft->val && !topRight->val && !bottomLeft->val && !bottomRight->val) {
        Node *ans = new Node(false, true);
        delete topLeft;
        delete topRight;
        delete bottomLeft;
        delete bottomRight;
        return ans;
    }
    Node *ans = new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    return ans;
}

Node* construct(vector<vector<int>>& grid) {
    return construct(grid, 0, 0, grid.size());
}

int main() {
    return 0;
}
