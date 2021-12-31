/*************************************************************************
	> File Name: 1.LeetCode642.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月31日 星期五 11时09分10秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

using PIS = pair<int, string>;

struct CountValue {
    int cnt;
    string s;

    CountValue() = default;
    CountValue(int cnt, string s) : cnt(cnt), s(s) {}

    bool operator<(const struct CountValue &that) const {
        return this->cnt == that.cnt ? this->s > that.s : this->cnt < that.cnt;
    }
};

struct Node {
    unordered_map<char, Node *> next;
    set<CountValue> top;

    Node() = default;
};

void insert(Node *root, string &s, int ind, int times) {
    if (!root) return ;
    CountValue temp(times, s);
    if (root->top.size() < 3) root->top.insert(temp);
    else if (*root->top.begin() < temp) {
        root->top.erase(root->top.begin());
        root->top.insert(temp);
    } 
    if (!s[ind]) return ;
    if (!root->next.count(s[ind])) root->next[s[ind]] = new Node();
    insert(root->next[s[ind]], s, ind + 1, times);
}

void add(Node *root, string &s, int times, int ind) {
    if (!root) return ;
    bool flag = false;
    CountValue temp(times, s);
    for (auto x : root->top) {
        if (x.s != s) continue;
        root->top.erase(x);
        root->top.insert(temp);
        flag = true;
        break;
    }
    if (!flag) {
        if (root->top.size() < 3) root->top.insert(temp);
        else if (*root->top.begin() < temp) {
            root->top.erase(root->top.begin());
            root->top.insert(temp);
        } 
    }
    if (!s[ind]) return ;
    if (!root->next.count(s[ind])) root->next[s[ind]] = new Node();
    add(root->next[s[ind]], s, times, ind + 1);
}

class AutocompleteSystem {
public:
    Node *root_;
    Node *cur_;
    string pre_;
    unordered_map<string, int> mp_;

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) : root_(new Node()), cur_(nullptr), pre_("") {
        cur_ = root_;
        int n = sentences.size();
        for (int i = 0; i < n; i++) {
            insert(root_, sentences[i], 0, times[i]);
            mp_[sentences[i]] = times[i];
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            cur_ = root_;
            mp_[pre_]++;
            add(root_, pre_, mp_[pre_], 0);
            pre_ = "";
            return {};
        }
        pre_ += c;
        if (cur_ == nullptr) return {};
        if (!cur_->next.count(c)) {
            cur_ = nullptr;
            return {};
        }
        cur_ = cur_->next[c];
        vector<string> ans;
        for (auto x: cur_->top) ans.push_back(x.s);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    return 0;
}
