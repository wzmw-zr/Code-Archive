/*************************************************************************
	> File Name: 6.HZOJ323.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月28日 星期二 16时10分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
#define MAX_N 10000

struct data {
    int p, d;
} Data[MAX_N + 5];

map<int, int> mp;

int n;

int main() {
    while (cin >> n) {
        memset(Data, 0, sizeof(Data));
        mp.clear();
        for (int i = 0; i < n; i++) {
            cin >> Data[i].p >> Data[i].d;
            mp[Data[i].d] = 0;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int tmp = mp[Data[i].d], p = Data[i].p;
            if (p > tmp) {
                mp[Data[i].d] = p;
                res += p - tmp;
            }
        }
        cout << res << endl;
    }
    return 0;
}
