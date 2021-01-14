/*************************************************************************
	> File Name: 1.LeetCode947.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月15日 星期五 00时11分18秒
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
    int degree;
    Node() = default;
    Node(int x, int y) : x(x), y(y), degree(0) {};
};

int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    vector<Node> nodes;
    unordered_map<int, vector<int>> row;
    unordered_map<int, vector<int>> col;
    for (int i = 0; i < n; i++) {
        if (!row.count(stones[i][0])) row[stones[i][0]] = vector<int>(0);
        if (!col.count(stones[i][1])) col[stones[i][1]] = vector<int>(0);
        nodes.push_back(Node(stones[i][0], stones[i][1]));
    }
    for (int i = 0; i < n; i++) {
        row[stones[i][0]].push_back(i);
        col[stones[i][1]].push_back(i);
    }
    for (int i = 0; i < n; i++) nodes[i].degree += row[stones[i][0]].size() + col[stones[i][1]].size() - 2;
    int ans = 0;
    while (1) {
        int flag = 0;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            if (nodes[i].degree == 0) continue;
            if (flag == 0) {
                ind = i;
                flag = 1;
                continue;
            }
            if (nodes[ind].degree > nodes[i].degree) ind = i;
        }
        if (flag == 0) break;
        ans++;
        int r = nodes[ind].x;
        int c = nodes[ind].y;
        nodes[ind].degree = 0;
        for (int &x : row[r]) {
            if (nodes[x].degree == 0) continue;
            nodes[x].degree--;
        }
        for (int &x : col[c]) {
            if (nodes[x].degree == 0) continue;
            nodes[x].degree--;
        }
    }
    return ans;
}

int main() {
    return 0;
}
