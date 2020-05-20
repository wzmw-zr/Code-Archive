/*************************************************************************
	> File Name: 7.HZOJ517.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月20日 星期三 19时41分37秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, ans;

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n - i; j++) {
            int t = n - i - j;
            if (i <= t && j <= t && i + j > t) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
