/*************************************************************************
	> File Name: 1.LeetCode451.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月03日 星期六 00时02分51秒
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

struct Node {
    char c;
    int cnt;

    Node() = default;
    Node(char c, int cnt = 0) : c(c), cnt(cnt) {}

    bool operator<(const Node &that) const {
        return this->cnt == that.cnt ? this->c < that.c : this->cnt > that.cnt;
    }
};

string frequencySort(string s) {
    unordered_map<char, Node> mp;
    for (auto c : s) {
        if (!mp.count(c)) mp[c] = Node(c);
        mp[c].cnt++;
    }
    vector<Node> nodes;
    for (auto &&[c, node] : mp) nodes.push_back(node);
    sort(nodes.begin(), nodes.end());
    string ans = "";
    for (auto node : nodes) {
        for (int i = 0; i < node.cnt; i++) ans += node.c;
    }
    return ans;
}

int main() {
    return 0;
}
