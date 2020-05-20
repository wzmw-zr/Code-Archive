/*************************************************************************
	> File Name: 8.HZOJ599.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月20日 星期三 19时58分43秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000000

long n, t;
long num[MAX_N + 5];

void b_s(int l, int r) {
    if (num[l] + num[r] == t) {
        cout << l << " " << r << endl;
        return ;
    }
    if (num[l] + num[r] > t) r--;
    else l++;
    b_s(l, r);
}

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> num[i];
    b_s(0, n - 1);
    return 0;
}
