/*************************************************************************
	> File Name: 2.HOJ221.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月06日 星期一 08时37分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
#define max_n 100000
using namespace std;

typedef struct child {
    int number;
    int b_n;
    int height;
} Child;
Child c[max_n + 5];
int balloon[max_n + 5] = {0};

int cmp(Child c1, Child c2) {
    return c1.height < c2.height;
}

int cmp1(Child c1, Child c2) {
    return c1.number < c2.number;
}

int main() {
    int n, m, height, temp = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) c[i].number = i, cin >> c[i].height;
    sort(c + 1, c + n + 1, cmp);
    for (int i = 1; i <= m; i++) cin >> height, balloon[height]++;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = temp; j <= c[i].height; j++) {
            if (!balloon[j]) continue;
            sum += balloon[j];
            balloon[j] = 0;
        }
        c[i].b_n = sum;
        temp = c[i].height;
    }
    sort(c + 1, c + n + 1, cmp1);
    for (int i = 1; i <= n; i++) cout << c[i].b_n << endl;
    return 0;
}
