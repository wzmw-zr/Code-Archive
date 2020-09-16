/*************************************************************************
	> File Name: 1.ACTire.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月16日 星期三 07时41分22秒
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
    State *start;
    map<State *, State *> fail;
    set<char> char_set;

    ACTire() : start(new State()) {
        fail[this->start] = this->start;
    }

    void insert(string s) {
        State *temp = this->start;
        for (int i = 0; s[i]; i++) {
            if (!temp->mp[s[i]]) temp->mp[s[i]] = new State();
            temp = temp->mp[s[i]];
            char_set.insert(s[i]);
        }
        temp->is_end = true;
    }

    void build() {
        queue<State *> que;
        for (auto &x : start->mp) {
            fail[x.second] = start;
            que.push(x.second);
        }
        while (!que.empty()) {
            State *temp = que.front();
            que.pop();
            for (auto &x : temp->mp) {
                State *s = fail[temp];
                while (s != start && !s->mp[x.first]) s = fail[s];
                if (s->mp[x.first]) fail[x.second] = s->mp[x.first];
                else fail[x.second] = start;
            }
        }
    }

    bool query(string s) {
        State *state = start;
        for (int i = 0; s[i]; i++) {
            if (state->mp[s[i]]) {
                state = state->mp[s[i]];
                if (state->is_end) return true;
                continue;
            } else {
                while (state != start && !state->mp[s[i]]) state = fail[state];
            }
        }
        return false;
    }

};

int main() {
    ACTire ac_tire;
    int n, m;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        ac_tire.insert(s);
    } 
    ac_tire.build();
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        cout << s << " : Match ? " << (ac_tire.query(s) ? "Yes" : "No") << endl;
    }
    return 0;
}
