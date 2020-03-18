/*************************************************************************
	> File Name: 2.HZOJ535.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月18日 星期三 18时14分30秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int h, w, sx, sy, ans = 1;
char mmap[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (mmap[tx][ty] == '.') {
            mmap[tx][ty] = 0;
            ans++;
            func(tx, ty);
        }
    }
}

int main() {
    cin >> h >> w;
    for (int i = 1; i <= w; i++) {
        cin >> (&mmap[i][1]);
    }
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            if (mmap[i][j] == '@') sx = i, sy = j;
        }
    }
    func(sx, sy);
    cout << ans << endl;
    return 0;
}

