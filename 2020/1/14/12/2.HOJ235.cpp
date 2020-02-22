/*************************************************************************
	> File Name: 2.HOJ235.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月12日 星期日 14时07分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cinttypes>
#include<cstdarg>
#include<algorithm>
#include<ctime>
#define max_n 1024
using namespace std;

int res[max_n + 5][15] = {0};
int temp[max_n + 5][15] = {0};

void get_val(int n) {
    if (n == 1) {
        res[1][0] = 1, res[1][1] = 1;
    }
    else get_val(n - 1);
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; temp[i][j]; j++) {
            temp[i][j] += 1;
        }
    }
}

int main() {
    int n;
    cin >> n;
    get_val(n);
    for (int i = 1; res[i][0]; i++) {
        for (int j = 1; res[i][j]; j++) {
            res[i][j + 1] && (cout << res[i][j] << " ");
            !res[i][j + 1] && (cout << res[i][j] << endl);
        }
    }
    return 0;
}
