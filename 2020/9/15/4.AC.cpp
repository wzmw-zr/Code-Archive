/*************************************************************************
	> File Name: 4.AC.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月15日 星期二 14时49分40秒
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
    bool is_end;
    map<char, State *> mp;

    State() : is_end(false) {}
};

struct ACTire {
    State *__root;
    map<State *, State *> fail;
    set<char> char_set;

    ACTire() : __root(new State()) {
        fail[__root] = __root;
    }

    void insert(string s) {
        State *state = __root;
        for (int i = 0; s[i]; i++) {
            if (state->mp[s[i]]) state->mp[s[i]] = new State();
            state = state->mp[s[i]];
            char_set.insert(s[i]);
        }
        state->is_end = true;
    }

    void build() {
        queue<State *> que;
        for (auto &x : __root->mp) que.push(x.second);
        while (!que.empty()) {
            State *temp = que.front();
            que.pop();
            for (auto &x : char_set) {
                State *state = temp;
                while (state != __root && !state->mp[x]) state = fail[state];
                if (state->mp[x]) {
                    fail[temp->mp[x]] = state->mp[x];
                    que.push(temp->mp[x]);
                } else {
                    fail[temp->mp[x]] = __root;
                }
            }
        }
    }
};

int main() {
    return 0;
}
