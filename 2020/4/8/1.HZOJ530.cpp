/*************************************************************************
	> File Name: 1.HZOJ530.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月08日 星期三 18时04分34秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

typedef struct Node {
    int x, y;
} Node;

int n, m, cnt;
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
char mmap[55][55];
int check[55][55];

int main() {
    cin >> n >> m;
    queue<Node> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '*') {
                que.push({i, j});    
                mmap[i][j] = '.';
                //check[i][j] = 1;
            }
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mmap[i][j];
        }
        cout << endl;
    }
    */
    cin >> cnt;
    while (cnt--) {
        string t;
        cin >> t;
        int dir_num = 0;
        if (t == "NORTH") {
            dir_num = 0;
        }
        if (t == "SOUTH") {
            dir_num = 1;
        }
        if (t == "WEST") {
            dir_num = 2;
        } 
        if (t == "EAST") {
            dir_num = 3;
        }
        memset(check, 0, sizeof(check));
        int times = que.size();
        for (int i = 0; i < times; i++) {
            Node tmp = que.front();
            que.pop();
            for (int j = 1; 1; j++) {
                int x = tmp.x + j * dir[dir_num][0];
                int y = tmp.y + j * dir[dir_num][1];
                if (mmap[x][y] != '.') break;
                if (!check[x][y]) {
                    que.push({x, y});
                    check[x][y] = 1;
                }
            }
        }
    }
    while (!que.empty()) {
        Node tmp = que.front();
        que.pop();
        mmap[tmp.x][tmp.y] = '*';
    }
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        cout << mmap[i][j];
    }
    cout << endl;
}
    return 0;
}
