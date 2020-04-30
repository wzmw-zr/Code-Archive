/*************************************************************************
	> File Name: 1.LeetCode202.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月30日 星期四 00时02分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

int cal(int n) {
    int ret = 0;
    while (n) {
        int tmp = n % 10;
        ret += tmp * tmp;
        n /= 10;
    }
    return ret;
}

bool isHappy(int n) {
    int t1 = n, t2 = cal(n);
    while (t1 != 1 && t2 != 1 && t1 != t2) {
        t1 = cal(t1);
        t2 = cal(t2);
        if (t2 == 1) break;
        t2 = cal(t2);
    }
    if (t1 == 1 || t2 == 1) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    cout << (isHappy(n) ? "Yes" : "No") << endl;
    return 0;
}
