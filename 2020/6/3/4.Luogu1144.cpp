/*************************************************************************
	> File Name: 4.Luogu1144.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月03日 星期三 20时35分39秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define MAX_N 1000000
#define MAX_M 2000000

struct edge {
    long end, val, next;
};

struct node {
    long now, val;
    bool operator< (const node &b) const {
        return this->val > b.val;
    }
};

long n, m, num;
long head[MAX_N + 5], ans[MAX_N + 5], ans_cnt[MAX_N + 5];
edge edg[MAX_M + 5];

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m;
    for (long i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;
        edg[num].end = b;
        edg[num].val = 1;
        edg[num].next = head[a];
        head[a] = num;
        num++;
        edg[num].end = a;
        edg[num].val = 1;
        edg[num].next = head[b];
        head[b] = num;
        num++;
    }
    priority_queue<node> que;
    que.push({1, 0});
    ans[1] = 0;
    ans_cnt[1] = 1;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.val > ans[temp.now]) continue;
        for (int cnt = head[temp.now]; cnt != -1; cnt = edg[cnt].next) {
            if (ans[edg[cnt].end] > temp.val + edg[cnt].val) {
                ans[edg[cnt].end] = temp.val + edg[cnt].val;
                ans_cnt[edg[cnt].end] = ans_cnt[temp.now];
                que.push({edg[cnt].end, ans[edg[cnt].end]});
            } else if (ans[edg[cnt].end] == temp.val + edg[cnt].val) {
                ans_cnt[edg[cnt].end] += ans_cnt[temp.now];
                ans_cnt[edg[cnt].end] %= 100003;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans_cnt[i] << endl;
    return 0;
}
