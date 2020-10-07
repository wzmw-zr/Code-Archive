/*************************************************************************
	> File Name: 3.LeetCode1513.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月07日 星期三 08时40分36秒
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

#define MOD 1000000007

int numSub(string s) {
    int n = s.size();
    long ans = 0;
    for (int i = 0; i < n; ) {
        while (s[i] && s[i] == '0') i++;
        int right = i;
        while (s[right] && s[right] == '1') right++;
        int len = right - i;
        ans += len * (len + 1) / 2;
        ans %= MOD;
        i = right;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << numSub(s) << endl;
    return 0;
}
