/*************************************************************************
	> File Name: 1.HOJ235.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月05日 星期日 15时37分52秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#include<ctime>
#define max_n 10
using namespace std;

int num[max_n + 5] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};

void get_number(int n, int start, int last) {
    if (start == last) {
        cout << last << endl;
        get_number(n, start, last + 1);
        return ;
    }
    for (int i = 0; i <= n - start; i++) {
        cout << start << " ";
        get_number(n, start + i, last);
    }
    start++;
    get_number(n, start, last);
}

int main() {
    int n;
    cin >> n;
    get_number(n, 1, 1);
    return 0;
}
