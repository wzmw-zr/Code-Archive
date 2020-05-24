/*************************************************************************
	> File Name: 8.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月24日 星期日 19时36分32秒
 ************************************************************************/

#include<iostream>
using namespace std;

int x, y, ans;

int check(int year) {
    if (year % 100 == 0) {
        if (year % 400 == 0) return 1;
        return 0;
    } 
    if (year % 4 == 0) return 1;
    return 0;
}

int main() {
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
        ans += check(i);
    }
    cout << ans << endl;
    return 0;
}
