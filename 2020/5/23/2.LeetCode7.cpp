/*************************************************************************
	> File Name: 2.LeetCode7.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月23日 星期六 10时19分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

int reverse(int x) {
    int ret = 0;
    while (x) {
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    return ret;
}

int main() {
    int x;
    cin >> x;
    cout << reverse(x) << endl;
    return 0;
}
