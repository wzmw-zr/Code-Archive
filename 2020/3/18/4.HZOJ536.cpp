/*************************************************************************
	> File Name: 4.HZOJ536.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月18日 星期三 18时46分23秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, ans, mmax;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
char mmap[105][105];

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (mmap[tx][ty] == '1') {
            ans++;
            mmap[tx][ty] = '0';
            func(tx, ty);
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
            if (mmap[i][j] == '1') {
                ans = 1;
                func(i, j);
                mmax = max(ans, mmax);
            }
        }
    }
    cout << mmax << endl;
    return 0;
}
