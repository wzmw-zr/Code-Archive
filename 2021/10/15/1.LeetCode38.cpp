/*************************************************************************
	> File Name: 1.LeetCode38.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月15日 星期五 08时14分31秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

string update(string &s) {
    string ans = "";
    int l = 0, r = 0;
    char c = s[0];
    while (s[r]) {
        while (s[r] && s[r] == c) r++;
        ans += to_string(r - l);
        ans += c;
        l = r;
        c = s[r];
    }
    return ans;
}

string countAndSay(int n) {
    string ans = "1";
    for (int i = 1; i < n; i++) ans = update(ans);
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << countAndSay(n) << endl;
    return 0;
}
