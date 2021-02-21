/*************************************************************************
	> File Name: 6.LeetCode5687.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月21日 星期日 10时58分13秒
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
    int x;
    int y;
    int val;
    Node() = default;
    Node(int x, int y, int val) : x(x), y(y), val(val) {}
};

int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size(), m = multipliers.size();
    vector<Node> nodes;
    for (int i = 0; i < m; i++) nodes.push_back(Node(i, i + n - m - 1, 0));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("[%d, %d], value = %d, mul = %d\n", nodes[j].x, nodes[j].y, nodes[j].val, multipliers[i]);
            printf("[%d, %d], value = %d\n", nodes[j + 1].x, nodes[j + 1].y, nodes[j + 1].val);
            nodes[j].val = max(nodes[j].val + multipliers[i] * nums[nodes[j].y + 1], nodes[j + 1].val + multipliers[i] * nums[nodes[j + 1].x - 1]);
            nodes[j].y++;
            printf("[%d, %d], value = %d\n\n", nodes[j].x, nodes[j].y, nodes[j].val);
        }
    }
    printf("=========================\n");
    return nodes[0].val;
}

int main() {
    return 0;
}
