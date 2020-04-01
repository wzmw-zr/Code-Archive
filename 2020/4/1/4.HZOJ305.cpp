/*************************************************************************
	> File Name: 4.HZOJ305.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 19时05分13秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

typedef struct Node {
    int x, y, step;
} Node;

int n, m, x, y, ans;
int dir[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};
char mmap[105][105];

int main() {
    queue<Node> que;
    cin >> m >> n >> y >> x;
    que.push({n - x + 1, y, 0});
    mmap[n - x + 1][y] = '*';
    for (int i = 1; i <= n; i++) cin >> &mmap[i][1];
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        ans = temp.step;
        for (int i = 0; i < 8; i++) {
            int x1 = temp.x + dir[i][0];
            int y1 = temp.y + dir[i][1];
            if (mmap[x][y] == '.') {
                mmap[x][y] = '*';
                que.push({x, y, temp.step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
