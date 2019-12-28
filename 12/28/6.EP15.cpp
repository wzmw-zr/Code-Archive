/*************************************************************************
	> File Name: 6.EP15.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月28日 星期六 15时39分22秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;


int main() {
    long m = 40, n = 20, ans = 1;
    while (m != 20 || n != 0) {
        if (m != 20) ans *= (m--);
        if (n != 0 && ans % n == 0) ans /= (n--);
    }
    cout << ans;
    return 0;
}
