/*************************************************************************
	> File Name: 6.HZOJ81.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 19时26分02秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

typedef struct Node {
    int x, y, s, f;
} Node;

int n, m;
char mmap[2005][2005];
int check[2005][2005];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int main() {
    cin >> n >> m;
    queue<Node> que;
    for (int i = 1; i <= n; i++)  {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                que.push({i, j, 0, 0});
                check[i][j] = 1;
            }
        }
    }
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (temp.f == 0 && check[x][y] & 1) continue;
            if (temp.f == 1 && check[x][y] & 2) continue;
            if (temp.f == 1 && mmap[x][y] == 'T') {
                cout << temp.s + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.' || mmap[x][y] == 'S' || mmap[x][y] == 'T') {
                que.push({x, y, temp.s + 1, temp.f});
                check[x][y] += temp.f + 1;
            }
            if (mmap[x][y] == 'P') {
                que.push({x, y, temp.s + 1, 1});
                check[x][y] = 3;
            }
        }
    }
    return 0;
}
