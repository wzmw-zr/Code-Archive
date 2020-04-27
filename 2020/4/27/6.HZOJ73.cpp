/*************************************************************************
	> File Name: 6.HZOJ73.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月27日 星期一 22时27分19秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;

int n, m, cnt;
char mmap[1005][1005];
int check[1005][1005];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

struct Node {
    int x, y;
};

void handle(int x, int y) {
    if (check[x][y]) return ;
    if (mmap[x][y] == 'X') {
        check[x][y] = 1;
        return ;
    }
    int flag = 0;
    queue<Node> que, res;
    que.push({x, y});
    while (!que.empty()) {
        Node tmp = que.front();
        que.pop();
        check[tmp.x][tmp.y] = 1;
        res.push(tmp);
        for (int i = 0; i < 4; i++) {
            int x_t = x + dir[i][0];
            int y_t = y + dir[i][1];
            if (x_t <= 0 || x_t > n || y_t <= 0 || y_t > m) {
                flag = 1; 
                continue;
            }
            if (check[x_t][y_t]) continue;
            if (mmap[x_t][y_t] == 'X') {
                check[x_t][y_t] = 1;
                continue;
            }
            que.push({x_t, y_t});
        }
    }
    if (!flag) cnt += res.size();
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> mmap[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            handle(i, j);
        }
    }
    cout << cnt << endl;
    return 0;
}
