/*************************************************************************
	> File Name: 2.PersistentSegmentTree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月22日 星期四 22时29分06秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define MAX_N 100000

struct Node {
    int cnt, left, right;
};

int n, m, total, len;
int nums[MAX_N + 5], ind[MAX_N + 5], rt[MAX_N + 5];
Node node[MAX_N << 5 + 5];

int getid(int &val) {
    return lower_bound(ind + 1, ind + len + 1, val) - ind; 
}

int build(int l, int r) {
    int root = ++total;
    if (l == r) return root;
    int mid = (l + r) >> 1;
    node[root].left = build(l, mid);
    node[root].right = build(mid + 1, r);
    node[root].cnt = node[node[root].left].cnt + node[node[root].right].cnt;
    return root;
}

int update(int k, int l, int r, int root) {
    int temp = ++total;
    node[temp].left = node[root].left, node[temp].right = node[root].right, node[temp].cnt = node[root].cnt + 1;
    if (l == r) return temp;
    int mid = (l + r) >> 1;
    if (k <= mid) node[temp].left = update(k, l, mid, node[root].left);
    else node[temp].right = update(k, mid + 1, r, node[root].right);
    node[temp].cnt = node[node[temp].left].cnt + node[node[temp].right].cnt;
    return temp;
}

int query(int u, int v, int l, int r, int k) {
    int mid = (l + r) >> 1;
    int x = node[node[v].left].cnt - node[node[u].left].cnt;
    if (l == r) return l;
    if (k <= x) return query(node[u].left, node[v].left, l, mid, k);
    return query(node[u].right, node[v].right, mid + 1, r, k - x);
}

void init() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    memcpy(ind, nums, sizeof(nums));
    sort(ind + 1, ind + n + 1);
    len = unique(ind + 1, ind + n + 1) - ind - 1;
    rt[0] = build(1, len);
    for (int i = 1; i <= n; i++) rt[i] = update(getid(nums[i]), 1, len, rt[i - 1]);
}

int l, r, k;
void work() {
    while (m--) {
        cin >> l >> r >> k;
        cout << ind[query(rt[l - 1], rt[r], 1, len, k)] << endl;
    }
}

int main() {
    return 0;
}
