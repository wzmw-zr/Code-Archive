/*************************************************************************
	> File Name: 3.HZOJ518.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月20日 星期三 18时23分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

int x, ans;

int main() {
    cin >> x;
    for (int i = 1, j = 1; i <= x; j++) {
        for (int k = 1; k <= j && i <= x; k++, i++) {
            ans += j;
        }
    }
    cout << ans << endl;
    return 0;
}
