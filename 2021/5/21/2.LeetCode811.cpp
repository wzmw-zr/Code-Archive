/*************************************************************************
	> File Name: 2.LeetCode811.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月21日 星期五 22时31分03秒
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
    string name;
    int cnt;
    unordered_map<string, Node *>  mp;

    Node() : name(""), cnt(0) {};
    Node(string name) : name(name), cnt(0) {}
    Node(string name, int cnt) : name(name), cnt(cnt) {}
};

void parse(string &s, vector<string> &names, int &cnt) {
    int ind = 0;
    string num = "";
    while (s[ind] && s[ind] != ' ') 
        num += s[ind++];
    ind++;
    while (s[ind]) {
        string name = "";
        while (s[ind] && s[ind] != '.') 
            name += s[ind++];
        if (s[ind]) ind++;
        names.push_back(name);
    }
    reverse(names.begin(), names.end());
    cnt = stoi(num);
}

string serialize(vector<string> &path, int &cnt) {
    string ans = "";
    int n = path.size();
    ans += to_string(cnt) + " ";
    for (int i = n - 1; i >= 0; i--) {
        ans += path[i];
        if (i) ans += ".";
    }
    return ans;
}

void dfs(Node *root, vector<string> &ans, vector<string> &path) {
    if (!root) return ;
    path.push_back(root->name);
    ans.push_back(serialize(path, root->cnt));
    for (auto &&[name, node] : root->mp) 
        dfs(node, ans, path);
    path.pop_back();
}


vector<string> subdomainVisits(vector<string>& cpdomains) {
    Node *root = new Node();
    for (string &s : cpdomains) {
        int cnt = 0;
        vector<string> names;
        parse(s, names, cnt);
        Node *temp = root;
        for (auto name : names) {
            if (!temp->mp.count(name)) 
                temp->mp[name] = new Node(name);
            temp->mp[name]->cnt += cnt;
            temp = temp->mp[name];
        }
    }
    vector<string> ans;
    vector<string> path;
    for (auto &&[name, node] : root->mp) dfs(node, ans, path);
    return ans;
}

int main() {
    return 0;
}
