/*************************************************************************
	> File Name: 1.HZOJ372.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 08时00分29秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 500000

int n;
int a[MAX_N + 5], b[MAX_N + 5];
int s_a[MAX_N + 5], s_b[MAX_N + 5];
int top_a = -1, top_b = -1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int i;
    for (i = 1; i <= n; i++) {
        while (top_a != -1 && a[s_a[top_a]] >= a[i]) top_a--;
        while (top_b != -1 && b[s_b[top_b]] >= b[i]) top_b--;
        if (top_a - top_b) break;
        s_a[++top_a] = i; 
        s_b[++top_b] = i; 
    }
    cout << i - 1 << endl;
    return 0;
}
