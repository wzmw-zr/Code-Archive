/*************************************************************************
	> File Name: 3.LeetCode69.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月08日 星期五 22时14分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

int mySqrt(int x) {
    int l = 1, r = x, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (mid <= x / mid) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    int x;
    cin >> x;
    cout << mySqrt(x) << endl;
    return 0;
}
