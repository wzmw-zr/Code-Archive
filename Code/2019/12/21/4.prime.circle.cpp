/*************************************************************************
	> File Name: 4.prime.circle.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月21日 星期六 11时13分21秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int now = ouput(1);
        n--;
        while (n) {
            for (int i = 1; i <= n; i++) {
                if (is_prime(now, i)) {
                    now = output(i);
                    n--;
                }
            }
        }
    }
    return 0;
}
