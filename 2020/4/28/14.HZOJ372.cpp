/*************************************************************************
	> File Name: 14.HZOJ372.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月28日 星期二 23时44分36秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 500000

int n;

struct MStack {
    int num[MAX_N + 5], s[MAX_N + 5], top;
};

MStack a, b;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a.num[i];
    for (int i = 1; i <= n; i++) cin >> b.num[i];
    a.top = b.top = -1;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cout << "val " << a.num[i] << " " << b.num[i] << endl;
        while (a.top != -1 && a.num[a.s[a.top]] >= a.num[i]) a.top--; 
        a.s[a.top++] = i;
        while (b.top != -1 && b.num[b.s[b.top]] >= b.num[i]) b.top--;
        b.s[b.top++] = i;
        cout << a.top << " " << b.top << " " << endl;
        if (a.top != b.top) break;
        else res = i;
    }
    cout << res << endl;
    return 0;
}
