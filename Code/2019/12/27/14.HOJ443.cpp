/*************************************************************************
	> File Name: 14.HOJ443.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 15时52分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 10000
#define max_m 100
using namespace std;

int tree[max_n + 5] = {0};

int main() {
    int l, m, count;
    int left, right;
    cin >> l >> m;
    for (int i = 0; i <= l; i++) tree[i] = 1;
    count = l + 1;
    for (int i = 1; i <= m; i++) {
        cin >> left >> right;
        for (int j = left; j <= right; j++) {
            if (!tree[j]) continue;
            tree[j] = 0;
            count--;
        }
    }
    cout << count;
    return 0;
}
