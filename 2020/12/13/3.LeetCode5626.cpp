/*************************************************************************
	> File Name: 3.LeetCode5626.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月13日 星期日 10时34分45秒
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
    int number;
    int cnt;
    Node() = default;
    Node(int number, int cnt) : number(number), cnt(cnt) {}
    bool operator<(const struct Node &a) const {
        return this->number < a.number;
    }
};

int minPartitions(string n) {
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; n[i]; i++) mp[n[i] - '0']++;
    vector<Node> nodes;
    for (auto &&[num, cnt] : mp) {
        if (num) nodes.push_back({num, cnt});
    }
    while (nodes.size()) {
        sort(nodes.begin(), nodes.end());
        ans += nodes[0].number;
        for (int i = 0; i < nodes.size(); i++) nodes[i].number -= nodes[0].number;
        nodes.erase(nodes.begin());
    }
    return ans;
}

int main() {
    return 0;
}
