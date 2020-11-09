/*************************************************************************
	> File Name: 25.HOJ454.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 18时25分46秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 1000
using namespace std;

int num[max_n + 5] = {0};

int main() {
    int n, temp, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        if (num[temp]) continue;
        num[temp] = 1;
        count++;
    }
    cout << count << endl;
    for (int i = 1; count; i++) {
        if (!num[i]) continue;
        count--;
        count && cout << i << " ";
        !count && cout << i;
    }
    return 0;
}
