/*************************************************************************
	> File Name: 24.HOJ453.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 18时17分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 10000
#define max_k 1000
using namespace std;

int num[max_n + 5] = {0};
int scale[30005] = {0};

int main() {
    int n, k, result;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        scale[num[i]]++;
    }
    for (int i = 1; k > 0 && i < 30005; i++) {
        if (!scale[i]) continue;
        k--;
        result = i;
    }
    k > 0 && cout << "NO RESULT";
    k == 0 && cout << result;
    return 0;
}
