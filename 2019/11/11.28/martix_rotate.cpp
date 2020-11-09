/*************************************************************************
	> File Name: martix_rotate.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月28日 星期四 17时41分41秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main () {
    int n, m;
    scanf("%d%d", &n, &m);
    int martix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &martix[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j > 0; j--) {
            printf("%d ", martix[j][i]);
        }
        printf("%d\n", martix[0][i]);
    }
    return 0;
}
