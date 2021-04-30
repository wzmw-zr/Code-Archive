/*************************************************************************
	> File Name: 2.LeetCode1772.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月01日 星期六 00时18分32秒
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
    string feature;
    int cnt;

    Node() = default;
    Node(string feature, int cnt) : feature(feature), cnt(cnt) {}
};

vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
    int n = features.size();
    unordered_map<string, int> mp;
    unordered_map<string, int> inds;
    for (int i = 0; i < n; i++) 
        mp[features[i]] = 0, inds[features[i]] = i;
    for (auto x : responses) {
        int ind = 0;
        unordered_set<string> check;
        while (x[ind]) {
            string temp = "";
            while (x[ind] && x[ind] == ' ') ind++;
            while (x[ind] && x[ind] != ' ') temp += x[ind++];
            check.insert(temp);
        }
        for (auto x : check) 
            if (mp.count(x)) mp[x]++;
    }
    auto cmp = [&](Node &a, Node &b) {
        return a.cnt == b.cnt ? inds[a.feature] < inds[b.feature] : a.cnt > b.cnt;
    };
    vector<Node> nodes;
    for (auto x : mp) nodes.push_back(Node(x.first, x.second));
    sort(nodes.begin(), nodes.end(), cmp);
    vector<string> ans;
    for (auto x : nodes) ans.push_back(x.feature);
    return ans;
}

int main() {
    return 0;
}
