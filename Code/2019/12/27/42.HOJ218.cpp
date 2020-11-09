/*************************************************************************
	> File Name: 42.HOJ218.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 22时44分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 100000
using namespace std;

typedef struct student {
    int num;
    int height;
} Student;

Student s[max_n + 5];

void merge(int left, int mid, int right) {
    Student temp[right - left + 1];
    int count = 0;
    int index_1 = left, index_2 = mid + 1;
    while (index_1 <= mid && index_2 <= right) {
        while (s[index_1].height <= s[index_2].height && index_1 <= mid) temp[count++] = s[index_1++];
        while (s[index_2].height <= s[index_1].height && index_2 <= right) temp[count++] = s[index_2++];
    }
    // shunxu
    if (index_1 <= mid) while (index_1 < mid) temp[count++] = s[index_1++];
    if (index_2 <= right) while (index_2 <= right) temp[count++] = s[index_2++];
    for (int i = 0; i < count; i++) s[left + i] = temp[i];
}

void merge_sort(int left, int right) {
    if (left == right) return ;
    int mid = (left + right) >> 1;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, mid, right);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        s[i].num = i;
        cin >> s[i].height;
    }
    merge_sort(1, n);
    for (int i = 1; i <= n; i++) {
        i == n && cout << s[i].num;
        i != n && cout << s[i].num << " ";
    }
    return 0;
}
