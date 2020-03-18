/*************************************************************************
	> File Name: 7.HZOJ405.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月18日 星期三 19时39分50秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

typedef struct Node {
    int x, y;
} Node;

int n, m, k, x, y, ans;
char mmap[3005][3005];
int check[3005][3005];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
queue<Node> que;

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (check[tx][ty] == 0 && mmap[tx][ty] != 0 && mmap[tx][ty] != mmap[x][y]) {
            ans++;
            check[tx][ty] = 1;
            que.push({tx, ty});
            func(tx, ty);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> (&mmap[i][1]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j] == 0) {
                ans = 1;
                check[i][j] = 1;
                que.push({i, j});
                func(i, j);
                while (!que.empty()) {
                    Node temp = que.front();
                    check[temp.x][temp.y] = ans;
                    que.pop();
                }
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        cout << check[x][y] << endl;
    }
    return 0;
}
