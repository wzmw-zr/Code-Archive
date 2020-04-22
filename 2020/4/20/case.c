/*************************************************************************
	> File Name: case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月20日 星期一 09时12分40秒
 ************************************************************************/

#include<stdio.h>
#define NUM 10

void print(int **num) {
    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < NUM; j++) {
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }
}

int dir[4][2] = {1, 0, 0, 1, 0, -1, -1, 0};

int main() {
    for (int i = 0; i < 4; i++) {
        printf("%d %d\n", dir[i][0], dir[i][1]);
    }
    return 0;
}
