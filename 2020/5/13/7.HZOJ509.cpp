/*************************************************************************
	> File Name: 7.HZOJ509.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月13日 星期三 20时51分06秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 500

struct Node {
    int t, c;
};

int m, n;
Node game[MAX_N + 5];

int cmp(Node a, Node b) {
    if (a.t != b.t) return a.t < b.t;
    return a.c > b.c;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> game[i].t;
    for (int i = 1; i <= n; i++) cin >> game[i].c;
    sort(game + 1, game + n + 1, cmp);
    for (int i = 1, t = 1; i <= n; i++) {
        if (game[i].t < t) {
            m -= game[i].c;   
            continue;
        }
        t++;
    }
    cout << m << endl;
    return 0;
}
