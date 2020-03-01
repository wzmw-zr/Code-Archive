/*************************************************************************
	> File Name: 2.HZOJ270.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月01日 星期日 16时01分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cinttypes>
#include<algorithm>
using namespace std;
#define MAX_N 300000
int s[MAX_N + 5];
int q[MAX_N + 5], head, tail;


int main() {
    int n, m, ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
    q[tail++] = 0;
    ans = s[1];
    for (int i = 1; i <= n; i++) {
        if (i - q[head] > m) head++;
        ans = max(ans, s[i] - s[q[head]]);
        while (tail - head && s[i] < s[q[tail - 1]]) tail--;
        q[tail++] = i;
    }
    printf("%d\n", ans);
    return 0;
}
