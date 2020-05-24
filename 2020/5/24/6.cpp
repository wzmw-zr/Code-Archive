/*************************************************************************
	> File Name: 6.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月24日 星期日 19时25分34秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, ans;

int main() {
    cin >> n;
    ans = n % 10;
    ans = ans * 10 + n / 10;
    cout << ans << endl;
    return 0;
}
