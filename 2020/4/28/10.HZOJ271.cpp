/*************************************************************************
	> File Name: 10.HZOJ271.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月28日 星期二 19时52分16秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define MAX_N 300000

int n, k;
int num[MAX_N + 5];
int q[MAX_N + 5], head = 0, tail = 0;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> num[i];
    for (int i = 1; i < k; i++) {
        while (tail - head && num[q[tail - 1]] > num[i]) tail--;
        q[tail++] = i;
    }
    for (int i = k; i <= n; i++) { 
        while (tail - head && num[q[tail - 1]] > num[i]) tail--;
        q[tail++] = i;
        if (q[head] <= i - k) head++;
        i == k || cout << " ";
        cout << num[q[head]];
    }
    cout << endl;
    head = tail = 0;
    for (int i = 1; i < k; i++) {
        while (tail - head && num[q[tail - 1]] < num[i]) tail--;
        q[tail++] = i;
    }
    for (int i = k; i <= n; i++) { 
        while (tail - head && num[q[tail - 1]] < num[i]) tail--;
        q[tail++] = i;
        if (q[head] <= i - k) head++;
        i == k || cout << " ";
        cout << num[q[head]];
    }
    cout << endl;
    return 0;
}
