/*************************************************************************
	> File Name: 8.HZOJ560.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 18时46分19秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 30000
#define MAX_M 25

int n, m;
struct data {
    int v, p;
} Data[MAX_M + 5]; 
int f[MAX_N + 5];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> Data[i].v >> Data[i].p;
    for (int i = 0; i < m; i++) {
        for (int j = n; j >= 0; j--) {
            if (j >= Data[i].v) f[j] = max(f[j], f[j - Data[i].v] + Data[i].v * Data[i].p);
        }
    }
    cout << f[n] << endl;
    return 0;
}
