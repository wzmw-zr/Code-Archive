/*************************************************************************
	> File Name: 3.LeetCode1899.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月30日 星期三 15时29分02秒
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
    vector<Node *> to;
    Node() = default;
    Node(string name) : name(name) {}
};

void split(string &s, string &name_1, string &name_2) {
    int ind = 1;
    while (s[ind] != ',')  name_1 += s[ind++];
    ind++;
    while (s[ind] != ')') name_2 += s[ind++];
}

void dfs(string s, unordered_map<string, Node *> &mp, unordered_map<string, bool> &check, vector<string> &temp) {
    if (check[s]) return ;
    temp.push_back(s);
    check[s] = true;
    for (auto &x : mp[s]->to) dfs(x->name, mp, check, temp);
}

void divide_str_int(string &s, string &name, string &num) {
    int ind = 0;
    while (s[ind] != '(') name += s[ind++];
    ind++;
    while (s[ind] != ')') num += s[ind++];
}

string get_name(string &s) {
    string name = "";
    int ind = 0;
    while (s[ind] != '(') name += s[ind++];
    return name;
}

vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
    unordered_map<string, Node *> mp;
    vector<string> Names;
    unordered_map<string, bool> check;
    for (string &s : names) {
        string name = get_name(s);
        Names.push_back(name);
        check[name] = false;
        mp[name] = new Node(name);
    }
    for (string &s : synonyms) {
        string name_1 = "", name_2 = "";
        split(s, name_1, name_2);
        mp[name_1]->to.push_back(mp[name_2]);
        mp[name_2]->to.push_back(mp[name_1]);
    } 
    vector<vector<string>> connected_component;
    for (string &s : Names) {
        vector<string> temp;
        dfs(s, mp, check, temp);
        if (temp.size()) connected_component.push_back(temp);
    }
    for (auto &x : connected_component) sort(x.begin(), x.end());
    unordered_map<string, string> same;
    for (auto &x : connected_component) {
        for (auto &y : x) same[y] = x[0];
    }
    unordered_map<string, int> cnt;
    for (string &s : names) {
        string name = "", num = "";
        divide_str_int(s, name, num);
        cnt[same[name]] += stoi(num);
    }
    vector<string> ans;
    for (auto &&[name, num] : cnt) ans.push_back(name + "(" + to_string(num) + ")");
    return ans;
}

int main() {
    return 0;
}
