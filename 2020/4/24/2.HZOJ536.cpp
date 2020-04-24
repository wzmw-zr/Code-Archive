/*************************************************************************
	> File Name: 2.HZOJ536.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月24日 星期五 09时51分43秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

int n, m;
char mmap[105][105];
int check[105][105];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int mmax;

int area(int x, int y) {
    int size = 0;
    if (mmap[x][y] == '0') {
        check[x][y] = 1;
        return size;
    }
    if (mmap[x][y] == '1' && check[x][y] == 0) {
        check[x][y] = 1;
        size++;
        for (int i = 0; i < 4; i++) {
            int x_t = x + dir[i][0];
            int y_t = y + dir[i][1];
            if (x_t < 1 || x_t > n || y_t < 1 || y_t > m || check[x_t][y_t]) continue;
            size += area(x_t, y_t);
        }
    }
    return size;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int tmp = area(i, j);
            mmax = max(mmax, tmp);
        }
    }
    cout << mmax << endl;
    return 0;
}
