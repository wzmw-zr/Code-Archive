/*************************************************************************
	> File Name: 1.c_arr.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月24日 星期日 15时57分32秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000
#define lowbit(x) ((x) & (-x))

int c[MAX_N + 5];

void add(int i, int val, int n) {
    while (i <= n) c[i] += val, i += lowbit(i);
}

int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        add(i, a, n);
    }
    for (int i = 1; i <= n; i++) {
        cout << i << " : " << c[i] << " " << query(i) << endl;
    }
    return 0;
}
