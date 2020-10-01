/*************************************************************************
	> File Name: 1.LeetCode1672.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月02日 星期五 07时08分50秒
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

long dp[20], last_num[20], ten_pow[20];

void init() {
    dp[1] = 1;
    ten_pow[0] = 1;
    ten_pow[1] = 10;
    for (int i = 2; i < 15; i++) {
        ten_pow[i] = 10 * ten_pow[i - 1];
        dp[i] = 10 * dp[i - 1] + ten_pow[i - 1];
    }
    for (int i = 1; i <= 11; i++) cout << dp[i] << " ";
    cout << endl;
}

int countDigitOne(int n) {
    init();
    int ind = 1, ans = 0;
    while (n) {
        int temp = n % 10;
        last_num[ind] = last_num[ind - 1] + temp * ten_pow[ind - 1];
        cout << "last sum : " << last_num[ind] << endl;
        ans += temp * dp[ind - 1];
        if (temp < 1) {}
        else if (temp == 1) ans += last_num[ind - 1] + 1;
        else ans += ten_pow[ind - 1];
        cout << ans << endl;
        n /= 10;
        ind++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << countDigitOne(n) << endl;
    return 0;
}
