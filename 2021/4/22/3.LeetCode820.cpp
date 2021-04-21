/*************************************************************************
	> File Name: 3.LeetCode820.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月22日 星期四 01时18分51秒
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
    unordered_map<char, Node *> mp;
    Node() = default;
};

void dfs(Node *root, int &ans, int depth) {
    if (!root) return ;
    if (root->mp.size() == 0) {
        ans += depth + 1;
        return ;
    }
    for (auto &&[c, next] : root->mp) dfs(next, ans, depth + 1);
}

int minimumLengthEncoding(vector<string>& words) {
    Node *root = new Node();
    for (auto word : words) {
        reverse(word.begin(), word.end());
        Node *temp = root;
        for (char c : word) {
            if (!temp->mp.count(c)) temp->mp[c] = new Node();
            temp = temp->mp[c];
        }
    }
    int ans = 0;
    dfs(root, ans, 0);
    return ans;
}

int main() {
    return 0;
}
