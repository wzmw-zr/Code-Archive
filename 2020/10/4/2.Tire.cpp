/*************************************************************************
	> File Name: 2.Tire.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月04日 星期日 10时17分26秒
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
    map<char, State *> mp;

    State() : __end(false) {}
};

struct Tire {
    State *__root;

    Tire() : __root(new State()) {};

    void insert(string s) {
        State *temp = __root;
        for (char &c : s) {
            if (!temp->mp.count(c)) temp->mp[c] = new State();
            temp = temp->mp[c];
        }
        temp->__end = true;
    }

    bool find(string s) {
        State *temp = __root;
        for (char &c : s) {
            if (!temp->mp.count(c)) return false;
            temp = temp->mp[c];
        }
        return temp->__end;
    }
};

Tire tire;
int op;
string s;

int main() {
    while (true) {
        cout << "op : ";
        cin >> op;
        cout << "string : ";
        cin >> s;
        if (op & 1) cout << (tire.find(s) ? "Match" : "Miss") << endl;
        else tire.insert(s);
    }
    return 0;
}
