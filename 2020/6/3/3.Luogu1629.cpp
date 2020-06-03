/*************************************************************************
	> File Name: 3.Luogu1629.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月03日 星期三 19时48分07秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MAX_N 1000
#define MAX_M 100000

struct edge {
    int e, val, next;
};

struct node {
    int now, val;
    bool operator< (const node &b) const {
        return this->val > b.val;
    }
};

int n, m, cnt;
int head1[MAX_N + 5], ans1[MAX_N + 5];
int head2[MAX_N + 5], ans2[MAX_N + 5];

edge edge1[MAX_M + 5];
edge edge2[MAX_M + 5];
char check[MAX_N + 5][MAX_N + 5];

int main() {
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
    memset(ans1, 0x3f, sizeof(ans1));
    memset(ans2, 0x3f, sizeof(ans2));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge1[i].e= b;
        edge1[i].val = c;
        edge1[i].next = head1[a];
        head1[a] = i;
        edge2[i].e = a;
        edge2[i].val = c;
        edge2[i].next = head2[b];
        head2[b] = i;
    }
    priority_queue<node> que;
    que.push({1, 0});
    ans1[1] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.val > ans1[temp.now]) continue;
        for (int cnt = head1[temp.now]; cnt != -1; cnt = edge1[cnt].next) {
            if (ans1[edge1[cnt].e] > temp.val + edge1[cnt].val) {
                ans1[edge1[cnt].e] = temp.val + edge1[cnt].val;
                que.push({edge1[cnt].e, ans1[edge1[cnt].e]});
            }
        }
    }
    que.push({1, 0});
    ans2[1] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.val > ans2[temp.now]) continue;
        for (int cnt = head2[temp.now]; cnt != -1; cnt = edge2[cnt].next) {
            if (ans2[edge2[cnt].e] > temp.val + edge2[cnt].val) {
                ans2[edge2[cnt].e] = temp.val + edge2[cnt].val;
                que.push({edge2[cnt].e, ans2[edge2[cnt].e]});
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += ans1[i] + ans2[i];
    }
    cout << ans << endl;
    return 0;
}
