/*************************************************************************
	> File Name: 1.LeetCode616.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月26日 星期六 07时24分43秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

struct State {
    int level;
    bool is_end;
    State *fail;
    map<char, State *> mp;

    State() = default;
    State(int level) : level(level), is_end(false), fail(nullptr) {}
};

struct ACTire {
    State *__root;   

    ACTire() : __root(new State(-1)) {}

    void insert(string s) {
        __insert(__root, s);
    }

    void __insert(State *root, string s) {
        for (int i = 0; s[i]; i++) {
            if (!root->mp[s[i]]) root->mp[s[i]] = new State(root->level + 1);
            root = root->mp[s[i]];
        }
        root->is_end = true;
    }

    void build() {
        queue<State *> que;
        __root->fail = __root;
        for (auto &x : __root->mp) {
            x.second->fail = __root;   
            que.push(x.second);
        }
        while (!que.empty()) {
            State *temp = que.front();
            que.pop();
            for (auto &x : temp->mp) {
                State *s = temp->fail;
                while (s != __root && s->mp[x.first]) s = s->fail;
                x.second->fail = s;
                que.push(x.second);
            }
        }
    }
};

string addBoldTag(string s, vector<string>& dict) {
    return s;
}

int main() {
    return 0;
}
