/*************************************************************************
	> File Name: 1.enumeration_palindrome.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月22日 星期二 14时36分14秒
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

int longest_palidrome(string s) {
    int len = s.size();
    vector<int> d1(len, 1), d2(len, 0);
    for (int i = 0; i < len; i++) {
        while (i - d1[i] >= 0 && i + d1[i] < len && s[i - d1[i]] == s[i + d1[i]]) d1[i]++;
    }
    for (int i = 0; i < len; i++) {
        while (i - d2[i] - 1 >= 0 && i + d2[i] < len && s[i - d2[i] - 1] == s[i + d2[i]]) d2[i]++;
    }
    int ans = 0;
    for (auto &x : d1) ans = max(ans, 2 * x - 1);
    for (auto &x : d2) ans = max(ans, 2 * x);
    return ans;
}

int main() {
    string s;
    getline(cin, s);
    cout << "longest_palidrome length : " << longest_palidrome(s) << endl;
    return 0;
}
