/*************************************************************************
	> File Name: 3.HZOJ543.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月24日 星期五 10时16分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

int n;
char mmap[25][25];
int check[25];

int exist(int ind) {
    int flag = 0;
    for (int i = 1; !flag && i <= n; i++) {
        if (check[i] != 1 && mmap[ind][i] == '1') flag = 1;
    }
    return flag;
}

int Methods(int ind) {
    int cnt = 0;
    if (ind > n) return 1;
    if (!exist(ind)) return cnt;
    for (int i = 1; i <= n; i++) {
        if (!check[i] && mmap[ind][i] == '1') {
            check[i] = 1;
            cnt += Methods(ind + 1);
            check[i] = 0;
        } 
    }
    return cnt;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 0; i <= n; i++) check[i] = 0;
    cout << Methods(1) << endl;
    return 0;
}
