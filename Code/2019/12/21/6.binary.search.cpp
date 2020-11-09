/*************************************************************************
	> File Name: 6.binary.search.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 22时14分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>
#define max_n 1000000
using namespace std;


int binary_search(int left, int right, int *numbers, int t) {
    int mid = (left + right) >> 1, ret;
    if (left > mid) return 0;
    if (t == numbers[mid]) return mid + 1;
    else if (t < numbers[mid]) ret = binary_search(left, mid - 1, numbers, t);
    else if (t > numbers[mid]) ret = binary_search(mid + 1, right, numbers, t);
    return ret;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int numbers[max_n + 5], target[max_n + 5];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &target[i]);
    }
    for (int i = 0; i < k; i++) {
        int res = binary_search(0, n - 1, numbers, target[i]);
        i == k - 1 && printf("%d", res);
        i != k - 1 && printf("%d ", res);
    }
    return 0;
}
