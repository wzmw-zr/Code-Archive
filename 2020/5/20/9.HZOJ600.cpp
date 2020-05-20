/*************************************************************************
	> File Name: 9.HZOJ600.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月20日 星期三 20时09分04秒
 ************************************************************************/

//#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_N 3000
#define MAX_M 3000

int n, m, t;
int mmap[MAX_N + 5][MAX_M + 5];

int b_s(int ind) {
    int l = 0, r = m - 1;
    while (l <= m) {
        int mid = (l + r) >> 1;
        if (mmap[ind][mid] == t) return mid;
        if (mmap[ind][mid] < t) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%d", &mmap[i][j]);
    }
    int x = n, y = 1;
    while (x > 0 && y <= m) {
        if (mmap[x][y] == t) {
            printf("%d %d\n", x, y);
            return 0;
        }
        if (mmap[x][y] > t) x--;
        else y++;
    }
    return 0;
}
