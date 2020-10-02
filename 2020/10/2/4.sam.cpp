/*************************************************************************
	> File Name: 4.sam.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月02日 星期五 20时00分31秒
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

#define MAX_N 100010

struct State {
    int len, link;
    map<char, int> next;
};

State st[MAX_N + 10];
int last, sz;

void sam_init() {
    st[0].len = 0;
    st[0].link = -1;
    last = 0;
    sz = 1;
}

void sam_add(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].link = st[q].link;
            st[clone].next = st[q].next;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
        }
    }
    last = cur;
}

string lcs(string &str_1, string &str_2) { 
    sam_init();
    for (int i = 0; str_1[i]; i++) sam_add(str_1[i]);
    int v = 0, l = 0, best_len = 0, best_pos = 0;
    for (int i = 0; str_2[i]; i++) {
        while (v && !st[v].next.count(str_2[i])) {
            v = st[v].link;
            l = st[v].len;
        }
        if (st[v].next.count(str_2[i])) {
            v = st[v].next[str_2[i]];
            l++;
        }
        if (l > best_len) {
            best_pos = l;
            best_len = i;
        }
    }
    return str_1.substr(best_pos - best_len + 1, best_len);
}

int main() {
    return 0;
}
