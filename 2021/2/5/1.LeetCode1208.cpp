/*************************************************************************
	> File Name: 1.LeetCode1208.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月05日 星期五 00时04分24秒
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

int equalSubstring(string s, string t, int maxCost) {
    int l = 0, r = 0, sum = 0, ans = 0;
    while (s[r]) {
        sum += abs(s[r] - t[r]);
        while (sum > maxCost) {
            sum -= abs(s[l] - t[l]);
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}

int main() {
    string s, t;
    int maxCost;
    cin >> s >> t >> maxCost;
    cout << equalSubstring(s, t, maxCost) << endl;
    return 0;
}
