/*************************************************************************
	> File Name: 3.LeetCode269.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月12日 星期五 13时51分56秒
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
    char ch;
    int in_degree;
    unordered_set<char> next;

    Node() = default;
    Node(char ch) : ch(ch), in_degree(0), next(unordered_set<char>()) {}
};

void build_graph(vector<string> words, unordered_map<char, Node> &graph) {
    if (!words.size()) return ;
    for (string s : words) cout << s << " ";
    cout << endl;
    vector<char> chs;
    for (string s : words) {
        if (!chs.size() || s[0] != *chs.rbegin()) chs.push_back(s[0]);
    }
    int n = chs.size();
    for (int i = 0; i < n; i++) {
        if (!graph.count(chs[i])) graph[chs[i]] = Node(chs[i]);
        for (int j = i + 1; j < n; j++) {
            if (!graph.count(chs[j])) graph[chs[j]] = Node(chs[j]);
            if (!graph[chs[i]].next.count(chs[j])) graph[chs[j]].in_degree++;
            graph[chs[i]].next.insert(chs[j]);
        }
    }
    unordered_map<char, vector<string>> mp;
    for (string s : words) {
        if (!mp.count(s[0])) mp[s[0]] = vector<string>(0);
        if (s.size() > 1) mp[s[0]].push_back(string(s.begin() + 1, s.end()));
    }
    for (auto &&[c, s_words] : mp) build_graph(s_words, graph);
}

string alienOrder(vector<string> &words) {
    int n = words.size();
    for (int i = 1; i < n; i++) {
        if (words[i][0] == words[i - 1][0]) {
            if (words[i].size() < words[i - 1].size() && string(words[i - 1].begin(), prev(words[i - 1].end())) == words[i]) return ""; 
        }
    }
    unordered_map<char, Node> graph;
    build_graph(words, graph);
    queue<char> que;
    for (auto &&[ch, node] : graph) {
        if (!node.in_degree) que.push(ch);
    }
    string ans = "";
    while (!que.empty()) {
        char ch = que.front();
        que.pop();
        ans += ch;
        cout << ch << endl;
        for (char c : graph[ch].next) {
            if (!(--graph[c].in_degree)) que.push(c);
        }
        graph.erase(ch);
    }
    if (graph.size()) return "";
    return ans;
}

int main() {
    vector<string> words;
    string s;
    while (cin >> s) words.push_back(s);
    for (auto x : words) cout << x << " ";
    cout << endl;
    cout << alienOrder(words) << endl;
    return 0;
}
