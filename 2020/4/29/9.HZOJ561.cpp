/*************************************************************************
	> File Name: 9.HZOJ561.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 19时10分59秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cinttypes>
using namespace std;
#define MAX_N 500
#define MAX_W 10000

int e, f, n;
struct Coin {
    int p, w;
} coin[MAX_N + 5];
int fa[MAX_W + 5];

int main() {
    cin >> e >> f >> n;
    memset(fa, 0x3f, sizeof(fa));
    fa[0] = 0;
    for (int i = 0; i < n; i++) cin >> coin[i].p >> coin[i].w;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= f - e; j++) {
            if (j >= coin[i].w) {
                fa[j] = min(fa[j], fa[j - coin[i].w] + coin[i].p);
            }
        }
    }
    if (fa[f - e] == 0x3f3f3f3f) {
        cout << "This is impossible." << endl;
    } else {
        cout << "The minimum amount of money in the piggy-bank is " <<  fa[f - e] << endl;
    }
    return 0;
}
