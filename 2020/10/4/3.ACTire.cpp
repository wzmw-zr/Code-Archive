/*************************************************************************
	> File Name: 3.ACTire.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月04日 星期日 10时28分04秒
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
    bool __end;
    State *fail;
    map<char, State *> mp;

    State() : __end(false), fail(this) {}
    State(State *fail) : __end(false), fail(fail) {}
};

struct ACTire {
    State *__root;   
    ACTire() : __root(new State()) {}

    void insert(string s) {
        State *temp = __root;
        for (char &c : s) {
            if (!temp->mp.count(c)) temp->mp[c] = new State();
            temp = temp->mp[c];
        }
        temp->__end = true;
    }

    void build() {
        queue<State *> que;
        for (auto &x : __root->mp) {
            x.second->fail = __root;
            que.push(x.second);
        }
        while (!que.empty()) {
            State *head = que.front();
            que.pop();
            for (auto &x : head->mp) {
                State *temp = head->fail;
                while (temp != __root && !temp->mp.count(x.first)) temp = temp->fail;
                if (temp->mp.count(x.first)) x.second->fail = temp->mp[x.first];
                else x.second->fail = __root;
                que.push(x.second);
            }
        }
    }

    bool find(string s) {
        State *st = __root;
        for (char &c : s) {
            while (st != __root && !st->mp.count(c)) st = st->fail;
            if (st->mp.count(c)) st = st->mp[c];
            if (st->__end) return true;
        }
        return false;
    }
};

ACTire actire;
int n;
string pattern, text;

int main() {
    cout << "Input pattern number : ";
    cin >> n;
    while (n) {
        cout << "pattern " << n << " : ";
        cin >> pattern;
        actire.insert(pattern);
        n--;
    }
    actire.build();
    while (true) {
        cout << "text : ";
        cin >> text;
        cout << (actire.find(text) ? "Match" : "Miss") << endl;
    }
    return 0;
}
