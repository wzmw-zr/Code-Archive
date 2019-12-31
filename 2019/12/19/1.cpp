/*************************************************************************
	> File Name: 1.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月19日 星期四 20时36分37秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#define MAX_N 10
using namespace std;


int arr[MAX_N + 5][MAX_N + 5];
int dir[8][2] = {
    {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
    {1, -2}, {1, 2}, {2, -1}, {2, 1}
};
int ans = 0;

void dfs(int x, int y, int n, int m, int count) {
    if (x < 0 || x >= n || y < 0 || y >= m) return ;
    if (arr[x][y] == 1) return ;
    if (count >= n * m) {
        ans += 1;
        return ;
    }
    arr[x][y] = 1;

    for (int i = 0; i < 8; i++) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        dfs(dx, dy, n, m, count + 1);
    }
    arr[x][y] = 0;
}

int main() {
    int T, n, m, sx, sy;
    int count = 1;
    scanf("%d", &T);
    while (T--) {
        memset(arr, 0, sizeof(arr));
        scanf("%d%d%d%d", &n, &m, &sx, &sy);
        dfs(sx, sy, n, m, count);
    }
    printf("%d\n", count);
    return 0;
}
