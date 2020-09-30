/*************************************************************************
	> File Name: 4.LeetCode319.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月30日 星期三 17时54分56秒
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

int bulbSwitch(int n) {
    vector<int> st(n, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j + i <= n; j += i) {
            st[j + i - 1] ^= 1;
        }
    }
    for (auto &x : st) cnt += x;
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << bulbSwitch(n) << endl;
    return 0;
}
