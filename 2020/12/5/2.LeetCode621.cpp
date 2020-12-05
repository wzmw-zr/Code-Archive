/*************************************************************************
	> File Name: 2.LeetCode621.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月05日 星期六 08时15分30秒
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
        return this->cnt < a.cnt;
    }
};

struct Iterm {
    char c;
    int end;
    Iterm() = default;
    Iterm(char c, int end) : c(c), end(end) {}
    bool operator<(const struct Iterm &a) const {
        return this->end > a.end;
    }
};

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> cnt, check;
    priority_queue<Node> que;
    priority_queue<Iterm> iterm;
    for (char c : tasks) cnt[c]++;
    for (auto &x : cnt) que.push({x.first, x.second});
    int ans = 1;
    while (!que.empty()) {
        vector<Node> temp;
        int flag = 0;
        while (!que.empty()) {
            Node t = que.top();
            que.pop();
            if (check[t.c]) {
                temp.push_back(t);
                continue;
            }
            if (--t.cnt) {
                iterm.push({t.c, ans + n + 1});
                check[t.c] = 1;
                temp.push_back(t);
            }
            flag = 1;
            break;
        }
        for (auto &x : temp) que.push(x);
        if (que.empty()) break;
        if (iterm.empty()) {
            ans++;
            continue;
        }
        Iterm head = iterm.top();
        if (!flag) {
            ans = head.end;
            check[head.c] = 0;
            iterm.pop();
        } else {
            if ((++ans) == head.end) {
                check[head.c] = 0;   
                iterm.pop();
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    char c;
    vector<char> tasks;
    while (cin >> c) tasks.push_back(c);
    cout << leastInterval(tasks, n) << endl;
    return 0;
}
