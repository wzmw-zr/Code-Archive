/*************************************************************************
	> File Name: 3.LeetCode1366.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月20日 星期六 15时20分28秒
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
    char c;
    vector<int> rank;
    Node() = default;
    Node(char c, int m) : c(c), rank(m, 0) {}

    bool operator<(const struct Node &a) const {
        for (int i = 0; i < (int) rank.size(); i++) {
            if (this->rank[i] == a.rank[i]) continue;
            return this->rank[i] > a.rank[i];
        }
        return this->c < a.c;
    }
};

string rankTeams(vector<string>& votes) {
    int n = votes.size();
    if (n == 1) return votes[0];
    int m = votes[0].size();
    unordered_map<char, Node> mp;
    for (int i = 0; votes[0][i]; i++) mp[votes[0][i]] = Node(votes[0][i], m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) mp[votes[i][j]].rank[j]++;
    }
    vector<Node> nodes;
    for (auto &&[c, node] : mp) nodes.push_back(node);
    sort(nodes.begin(), nodes.end());
    string ans = "";
    for (auto &node : nodes) ans += node.c;
    return ans;
}

int main() {
    return 0;
}
