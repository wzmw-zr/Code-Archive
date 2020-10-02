/*************************************************************************
	> File Name: 2.sam.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月02日 星期五 12时10分20秒
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

State st[MAX_N * 2 + 10];
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
        if (st[q].len == st[p].len + 1) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].link = st[q].link;
            st[clone].next = st[q].next;
            st[cur].link = st[q].link = clone;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
        }
    }
    last = cur;
}

int substring_cnt() {
    int cnt = 0;
    for (int i = 1; i < sz; i++) cnt += st[i].len - st[st[i].link].len;
    return cnt;
}

int substring_len() {
    int cnt = 0;
    for (int i = 1; i < sz; i++) {
        cnt += st[i].len * (st[i].len + 1) / 2 - st[st[i].link].len * (st[st[i].link].len + 1) / 2;
    }
    return cnt;
}

int main() {
    return 0;
}
