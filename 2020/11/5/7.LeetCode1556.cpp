/*************************************************************************
	> File Name: 7.LeetCode1556.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月05日 星期四 22时32分57秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

string thousandSeparator(int n) {
    string ans = "";
    int cnt = 0;
    do {
        if (cnt == 3) {
            ans = "." + ans;
            ans = to_string(n % 10) + ans;
            cnt = 1;
        } else {
            ans = to_string(n % 10) + ans;
            cnt++;
        }
        n /= 10;
    } while (n);
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << thousandSeparator(n) << endl;
    return 0;
}
