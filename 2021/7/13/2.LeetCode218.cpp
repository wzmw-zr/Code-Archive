/*************************************************************************
	> File Name: 2.LeetCode218.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月13日 星期二 10时02分03秒
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

#define L_END 0
#define R_END 1

struct Node {
    int ind;
    int type;
    int height;

    Node() = default;
    Node(int ind, int type, int height) : ind(ind), type(type), height(height) {}

    bool operator <(const struct Node &that) const {
        return this->ind == that.ind ? this->type < that.type : this->ind < that.ind;
    }
};

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<Node> nodes;
    for (auto building : buildings) {
        nodes.push_back({building[0], L_END, building[2]});
        nodes.push_back({building[1], R_END, building[2]});
    }
    sort(nodes.begin(), nodes.end());
    multiset<int> st;
    st.insert(0);
    map<int, int> mp;
    for (auto node : nodes) {
        if (node.type == L_END) {
            if (node.height > *st.rbegin())  
                mp[node.ind] = node.height;
            st.insert(node.height);
        } else {
            st.erase(st.find(node.height));
            if (node.height > *st.rbegin()) 
                mp[node.ind] = *st.rbegin();
        }
    }
    vector<vector<int>> ans;
    for (auto &&[ind, height] : mp) ans.push_back({ind, height});
    return ans;
}

int main() {
    return 0;
}
