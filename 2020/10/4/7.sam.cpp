/*************************************************************************
	> File Name: 7.sam.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月04日 星期日 14时35分43秒
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

State st[MAX_N << 1 + 10];
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
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len;
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


int main() {
    return 0;
}
