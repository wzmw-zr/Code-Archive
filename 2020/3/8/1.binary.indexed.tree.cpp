/*************************************************************************
	> File Name: 1.binary.indexed.tree.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月08日 星期日 08时47分15秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
#define lowbit(i) (i & (-i))
#define MAX_N 1000

int number[MAX_N + 1], n, temp;

void add(int *arr, int size, int ind, int value) {
    while (ind <= size) arr[ind] += value, ind += lowbit(ind);
}

int query(int *arr, int ind) {
    int ret = 0;
    while (ind) ret += arr[ind], ind -= lowbit(ind);
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &temp), add(number, n, i, temp);
    for (int i = 1; i <= n; i++) printf("sum of previous %d items is %d\n", i, query(number, i));
    return 0;
}
