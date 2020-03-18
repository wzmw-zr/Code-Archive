/*************************************************************************
	> File Name: 6.HZOJ404.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月18日 星期三 19时21分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, ans = 1, x, y;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
char mmap[3005][3005];
int check[3005][3005];

void func(int x, int y) {
    check[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0]; 
        int ty = y + dir[i][1];
        if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
        if (check[tx][ty] != 1 && mmap[tx][ty] != mmap[x][y]) {
            check[tx][ty] = 1;
            ans++;
            func(tx, ty);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> (&mmap[i][1]);
    cin >> x >> y;
    check[x][y] = 1;
    func(x, y);
    cout << ans << endl;
    return 0;
}
