/*************************************************************************
	> File Name: 6.HZOJ80.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月11日 星期三 20时42分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int n, m, sx, sy;
char mmap[505][505];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int func(int x, int y) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (mmap[tx][ty] == 'g') return 1;
        if (mmap[tx][ty] == '.') {
            mmap[tx][ty] = '*';
            ret |= func(tx, ty);
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 's') {
                sx = i;
                sy = j;
            }
        }
    }
    if (func(sx, sy)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
