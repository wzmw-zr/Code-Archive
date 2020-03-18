/*************************************************************************
	> File Name: 5.HZOJ406.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月18日 星期三 19时02分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, ans;
int dir[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};
char mmap[2005][2005];

void func(int x, int y) {
    mmap[x][y] = '.';
    for (int i = 0; i < 8; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (mmap[tx][ty] == '#') {
            func(tx, ty);
            ans--;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (&mmap[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] == '#') ans++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] == '#') {
                func(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
