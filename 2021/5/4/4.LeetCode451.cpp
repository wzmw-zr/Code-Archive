/*************************************************************************
	> File Name: 4.LeetCode451.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月04日 星期二 22时17分20秒
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
    int cnt;

    Node() = default;
    Node(char c, int cnt) : c(c), cnt(cnt) {}
    
    bool operator<(const struct Node &a) const {
        return this->cnt == a.cnt ? this->c < a.c : this->cnt > a.cnt;
    }
};

string frequencySort(string s) {
    unordered_map<char, int> mp;
    for (char c : s) 
        mp[c]++;
    vector<Node> nodes;
    for (auto &&[c, cnt] : mp) 
        nodes.push_back(Node(c, cnt));
    sort(nodes.begin(), nodes.end());
    string ans = "";
    for (auto &node : nodes) {
        for (int i = 0; i < node.cnt; i++)
            ans += node.c;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << frequencySort(s) << endl;
    return 0;
}
