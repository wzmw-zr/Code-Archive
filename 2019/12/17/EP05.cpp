/*************************************************************************
	> File Name: EP05.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月17日 星期二 18时36分21秒
 ************************************************************************/

#include<iostream>
using namespace std;


int gcd(int ans, int i) {
    if(i == 0) return ans;
    else return gcd(i, ans % i);
}



int lcm(int ans, int i) {
    return ans * i / gcd (ans, i);
}


int main() {
    int ans = 1;
    for (int i = 1; i <= 20; i++) {
        if (ans % i == 0) continue;
        ans *= i / gcd(ans, i);
    }
    printf("%d\n", ans);
    return 0;
}
