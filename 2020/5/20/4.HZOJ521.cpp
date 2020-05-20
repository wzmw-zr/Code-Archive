/*************************************************************************
	> File Name: 4.HZOJ521.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月20日 星期三 18时34分49秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 3000005
#define N 35

int n, r, ans;
int num[N];
int prime[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) prime[i] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) continue;
        for (int j = 2; i * j < MAX_N; j++) prime[i * j] = 0;
    }
}

void func(int s, int sum, int number) {
    if (number > n || s > n) return ;
    if (number == r) {
        ans += prime[sum];
        return ;
    }
    for (int i = s; i < n - r + number + 1; i++) {
        func(i + 1, sum + num[i], number + 1);
    }
}

int main() {
    init();
    cin >> n >> r;
    for (int i = 0; i < n; i++) cin >> num[i];
    func(0, 0, 0);
    cout << ans << endl;
    return 0;
}
