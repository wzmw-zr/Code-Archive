/*************************************************************************
	> File Name: 1.HOJ486.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月10日 星期五 19时07分44秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cinttypes>
#include<cstdarg>
#include<algorithm>
#include<ctime>
#define max_n 1000
using namespace std;

int num[max_n + 5] = {0};

int main() {
    int n;
    cin >> n;
    num[1] = 1;
    num[2] = 3;
    for (int i = 3; i <= n; i++) {
        num[i] = (num[i - 1] + 2 * num[i - 2]) % 12345;
    }
    cout << num[n] << endl;
    return 0;
}
