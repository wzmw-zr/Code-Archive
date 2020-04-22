/*************************************************************************
	> File Name: 3.HZOJ392.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月22日 星期三 18时50分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

long a, b, num[100005], mmax;

int check(int mid) {
    int cnt = 1, now = 0;
    for (int i = 1; i < a; i++) {
        if (num[i] - num[now] >= mid) {
            cnt++;
            now = i;
        }
    }
    return cnt;
}

long func() {
    long l = 1, r = mmax;
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        int cnt = check(mid);
        if (cnt >= b) l = mid;
        else r = mid - 1;
    }
    return l;
}


int main() {
    cin >> a >> b;
    for (long i = 0; i < a; i++) {
        cin >> num[i];
    }
    sort(num, num + a);
    mmax = num[a - 1] - num[0];
    cout << func() << endl;
    return 0;
}
