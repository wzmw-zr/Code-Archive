/*************************************************************************
	> File Name: 3.LeetCode409.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月22日 星期日 07时50分38秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> mp;
    int ans = 0, flag = 0;
    for (char c : s) mp[c]++;
    for (auto &x : mp) {
        if (x.second & 1) {
            if (!flag) {
                ans += x.second;
                flag = 1;
            } else ans += x.second - 1;
        } else ans += x.second;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}
