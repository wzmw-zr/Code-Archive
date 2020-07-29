/*************************************************************************
	> File Name: 2.topo.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月29日 星期三 18时42分23秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct Edge {
    int to, next;
};

Edge edg[10000];
int n, m, head[50], in_degree[50];

void insert_edge(int a, int b, int x) {
    edg[x].to = b;
    edg[x].next = head[a];
    head[a] = x;
    in_degree[b]++;
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        insert_edge(a, b, i);
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (in_degree[i]) continue;
        que.push(i);
    }
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        cout << temp << " ";
        for (int ind = head[temp]; ind != -1; ind = edg[ind].next) {
            int to = edg[ind].to;
            in_degree[to]--;
            if (in_degree[to] == 0) que.push(to);
        }
    }
    return 0;
}
