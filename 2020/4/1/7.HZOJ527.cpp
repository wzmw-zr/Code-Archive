/*************************************************************************
	> File Name: 7.HZOJ527.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 20时01分20秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

typedef struct Node {
    int x, y, s, d;
} Node;

int m, n, d;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
char mmap[105][105];
int check[105][105][105];

int main() {
    cin >> m >> n >> d;
    for (int i = 1; i <= m; i++) cin >> &mmap[i][1]; 
    queue<Node> que;
    que.push({1, 1, 0, d});
    for (int i = 0; i <= d; i++) check[1][1][i] = 1;
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            for (int j = 2; j <= temp.d; j++) {
                int x = temp.x + j * dir[i][0];
                int y = temp.y + j * dir[i][1];
                if (x == n && y == m) {
                    cout << temp.s + 1 << endl;
                    return 0;
                }
                if (mmap[x][y] == 0) break;
                if (mmap[x][y] == 'P' && check[x][y][temp.d - j] == 0) {
                    check[x][y][temp.d - j] = 1;
                    que.push({x, y, temp.s + 1, temp.d - j});
                } 
            }
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x == n && y == m) {
                cout << temp.s + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == 'P' && check[x][y][temp.d] == 0) {
                check[x][y][temp.d] = 1;
                que.push({x, y, temp.s + 1, temp.d});
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}
