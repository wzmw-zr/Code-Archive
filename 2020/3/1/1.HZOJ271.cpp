/*************************************************************************
	> File Name: 1.HZOJ271.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月01日 星期日 09时29分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
#define MAX_N 100000

int arr[MAX_N + 5];
int q[MAX_N + 5], head, tail;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        while (tail - head && arr[i] < arr[tail - 1]) tail--;
        q[tail++] = i;
        if (i + 1 < k) continue;
        if (i - q[head] == k) head++;
        i + 1 == k || cout << " ";
        cout << arr[q[head]];
    }
    return 0;
}
