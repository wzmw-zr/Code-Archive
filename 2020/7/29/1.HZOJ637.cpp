/*************************************************************************
	> File Name: 1.HZOJ637.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月29日 星期三 18时15分53秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct Edge {
    int to, next;
};

int n, m, head[30], in_degree[30], edg_cnt, ans_cnt;
int ans[30];
Edge edg[10000];

void insert_edge(int a, int b, int x) {
    edg[x].to = b;
    edg[x].next = head[a];
    head[a] = x;
    edg_cnt = x + 1;
    in_degree[b]++;
}

int check() {
    int temp_in[30];
    ans_cnt = 0;
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        temp_in[i] = in_degree[i];
        if (temp_in[i] == 0) {
            que.push(i);
        }
    }
    int f1 = que.size();
    int f2 = 0;
    while (!que.empty()) {
        int t = que.front();
        int f3 = 0;
        que.pop();
        ans[++ans_cnt] = t + 'A' - 1;
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            temp_in[e]--;
            if (temp_in[e] == 0) {
                if (f3 == 1) {
                    f3 == 2;
                } else if (f3 == 0) {
                    f3 = 1;
                }
                que.push(e);
            }
        }
        if (f3 == 2) f2 = 2;
    }
    for (int i = 1; i <= n; i++) {
        if (temp_in[i]) {
            return 1;
        }
    }
    if (f1 != 1 || f2 == 2) {
        return 0;
    }
    return 2;
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b >> b;
        insert_edge(a - 'A' + 1, b - 'A' + 1, i);
        int t = check(); // if t = 0, normal, t = 1, wrong, t = 2, ans;
        if (t == 1) {
            cout << "Inconsistency found after " << i + 1 << " relations." << endl;
            return 0;
        } else if (t == 2) {
            cout << "Sorted sequence determined after " << i + 1 << " relations: ";
            for (int i = 1; i <= ans_cnt; i++) {
                cout << (char) ans[i];
            }
            cout << "." << endl;
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined." << endl;
    return 0;
}
