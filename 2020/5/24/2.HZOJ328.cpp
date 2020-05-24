/*************************************************************************
	> File Name: 2.HZOJ328.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月24日 星期日 16时30分03秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAX_N 200000
#define lowbit(x) ((x) & (-x))
#define swap(a, b) {\
    __typeof(a) temp = a;\
    a = b;\
    b = temp;\
}

long num[MAX_N + 5], temp[MAX_N + 5];
long less_pre[MAX_N + 5], less_after[MAX_N + 5];
long more_pre[MAX_N + 5], more_after[MAX_N + 5];

void add(long *nums, long i, long val, long n) {
    while (i <= n) nums[i] += val, i += lowbit(i);
}

long query(long *nums, long i) {
    long sum = 0;
    while (i) {
        sum += nums[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    long n, a;
    cin >> n;
    for (long i = 1; i <= n; i++) {
        cin >> num[i];
        less_pre[num[i]] = query(temp, num[i]);
        more_pre[num[i]] = i - less_pre[num[i]] - 1;
        add(temp, num[i], 1, n);
    }
    memset(temp, 0, sizeof(temp));
    long l = 1, r = n;
    while (l < r) {
        swap(num[l], num[r]);
        l++, r--;
    }
    for (long i = 1; i <= n; i++) {
        less_after[num[i]] = query(temp, num[i]);
        more_after[num[i]] = i - less_after[num[i]] - 1;
        add(temp, num[i], 1, n);
    }
    long sum1 = 0, sum2 = 0;
    for (long i = 1; i <= n; i++) {
        sum1 += less_pre[num[i]] * less_after[num[i]];
        sum2 += more_pre[num[i]] * more_after[num[i]];
    }
    cout << sum2 << " " << sum1 << endl;
    return 0;

}
