/*************************************************************************
	> File Name: 6.merge_sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月23日 星期六 19时58分28秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int merge_sort(int *num, int n) {
    if (n <= 1) return 0;
    int ans = 0, mid = n / 2;
    ans += merge_sort(num, mid);
    ans += merge_sort(num + mid, n - mid);
    int *temp = (int *) malloc(sizeof(int) * n);
    int p1 = 0, p2 = mid, k = 0;
    while (p1 < mid || p2 < n) {
        if (p1 < mid && ((p2 == n) || (num[p1] <= num[p2]))) 
            temp[k++] = num[p1++];
        else ans += mid - p1, temp[k++] = num[p2++];
    } 
    for (int i = 0; i < k; i++) num[i] = temp[i];
    return ans;
}

int main() {
    int n;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++) cin >> num[i];
    cout << merge_sort(num, n) << endl;
    return 0;
}
