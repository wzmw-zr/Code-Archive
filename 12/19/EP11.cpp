/*************************************************************************
	> File Name: EP11.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月19日 星期四 20时01分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#define MAX_N 20
using namespace std;

int grid[MAX_N + 5][MAX_N + 5] = {0};

int dir[4][2] = {
    {-1, -1}, {-1, 0},
    {-1, 1}, {0, 1}
};

int calc(int x, int y) {
    int ans = 0;
    for (int k = 0; k < 4; k++) {
        int p = 1;
        for (int step = 0; step < 4; step++) {
            int dx = x + step * dir[k][0];
            int dy = y + step * dir[k][1];
            if (dx < 0 || dx >= MAX_N) break;
            if (dy < 0 || dy >= MAX_N) break;
            p *= grid[dx][dy];
        }
        if (p > ans) ans = p;
    }
    return ans;
} 

int main() {
    int ans = 0;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            scanf("%d", &grid[i][j]);
        }
    } 

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            int p = calc(i, j);
            if (p > ans) ans = p;
        }
    }
    printf("%d\n", ans);
    return 0; 
}
