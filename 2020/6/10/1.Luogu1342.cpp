/*************************************************************************
	> File Name: 1.Luogu1342.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月10日 星期三 18时04分49秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX_N 1000000
#define MAX_M 1000000

struct Data {
    long end, dis;
    
    bool operator< (const Data &b) const {
        return this->dis > b.dis;
    }
};

struct Node {
    long end, dis, next;
};

long n, m, cnt1, cnt2;
long head1[MAX_N + 5];
Node edge1[MAX_M + 5];
long check1[MAX_N + 5];
long ans1;
long head2[MAX_N + 5];
Node edge2[MAX_M + 5];
long check2[MAX_N + 5];
long ans2;

int main() {
    cin >> n >> m;
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
    for (long i = 0; i < m; i++) {
        long u, v, w;
        cin >> u >> v >> w; 
        long tmp = head1[u];
        while (tmp != -1) {
            if (edge1[tmp].end == v) {
                edge1[tmp].dis = min(edge1[tmp].dis, w);
                break;
            } 
            else tmp = edge1[tmp].next;
        }
        if (tmp == -1) {
            edge1[cnt1].end = v;
            edge1[cnt1].dis = w;
            edge1[cnt1].next = head1[u];
            head1[u] = cnt1;
            cnt1++;
        }

        tmp = head2[v];
        while (tmp != -1) {
            if (edge2[tmp].end == u) {
                edge2[tmp].dis = min(edge2[tmp].dis, w);
                break;
            } 
            else tmp = edge2[tmp].next;
        }
        if (tmp == -1) {
            edge2[cnt2].end = u;
            edge2[cnt2].dis = w;
            edge2[cnt2].next = head2[v];
            head2[v] = cnt2;
            cnt2++;
        }

    }

    priority_queue<Data> que;
    que.push({1, 0});
    while (!que.empty()) {
        Data tmp = que.top();
        que.pop();
        if (check1[tmp.end]) continue;
        //cout << "end = " << tmp.end << " dis = " << tmp.dis << endl;
        check1[tmp.end] = 1;
        ans1 += tmp.dis;
        long ind = head1[tmp.end];
        while (ind != -1) {
            que.push({edge1[ind].end, tmp.dis + edge1[ind].dis});
            ind = edge1[ind].next;
        }
    }

    que.push({1, 0});
    while (!que.empty()) {
        Data tmp = que.top();
        que.pop();
        if (check2[tmp.end]) continue;
        //cout << "end = " << tmp.end << " dis = " << tmp.dis << endl;
        check2[tmp.end] = 1;
        ans2 += tmp.dis;
        long ind = head2[tmp.end];
        while (ind != -1) {
            que.push({edge2[ind].end, tmp.dis + edge2[ind].dis});
            ind = edge2[ind].next;
        }
    }
    cout << ans1 + ans2 << endl;
    return 0;
}
