/*************************************************************************
	> File Name: 8.d.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月30日 星期六 16时09分15秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000
#define MAX_M 100000

int n, m;
int num[MAX_N + 5], mmax;

int b_s(int l, int r) {
    int mid = (l + r) >> 1;
    int res = check(mid);

}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        num[i] *= 1000;
        mmax = max(mmax, num[i]);
        num[i] += num[i - 1];
    }
    cout << b_s(0, mmax) << endl;
    return 0;
}
