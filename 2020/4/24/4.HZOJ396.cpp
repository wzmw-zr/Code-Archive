/*************************************************************************
	> File Name: 4.HZOJ396.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月24日 星期五 22时57分41秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

typedef struct Node {
    int x, y;
} Node;

int n;
int mmap[35][35];
int check[35][35];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void output() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            j != 1 && cout << " ";
            cout << mmap[i][j];
        }
        cout << endl;
    }
}

int closure(queue<Node> &que, int x, int y) {
    int ret = 1;
    que.push({x, y});
    check[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int x_t = x + dir[i][0];
        int y_t = y + dir[i][1];
        if (x_t <= 0 || x_t > n || y_t <= 0 || y_t > n) {
            ret = 0;
            continue;
        }
        if (check[x_t][y_t]) continue;
        if (check[x_t][y_t] == -1) return 0;
        if (!mmap[x_t][y_t]) ret &= closure(que, x_t, y_t);
    }
    return ret;
}

void handle(int x, int y) {
    if (check[x][y]) return ;
    if (mmap[x][y] == 1) {
        check[x][y] = 1;
        return ;
    }
    queue<Node> que;
    //int ret = closure(que, x, y);
    if (!closure(que, x, y)) {
        while (!que.empty()) {
            Node temp = que.front();
            que.pop();
            check[temp.x][temp.y] = -1;
        }
        return ;
    }
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        mmap[temp.x][temp.y] = 2;
        check[temp.x][temp.y] = 1;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            handle(i, j);
        }
    }
    output();
    return 0;
}
