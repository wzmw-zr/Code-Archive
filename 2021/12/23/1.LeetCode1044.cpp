/*************************************************************************
	> File Name: 1.LeetCode1044.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月23日 星期四 09时48分31秒
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
#include <ctime>
using namespace std;

// WA
long wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

long MOD = 1e9 + 7;
long mod1;
long mod2;

string check(string &s, vector<long> &base1, vector<long> &base2, long len) {
    unordered_map<long, unordered_set<long>> mp1;
    unordered_map<long, unordered_set<long>> mp2;
    long n = s.size();
    long h1 = 0, h2 = 0;
    for (long i = 0; i < len; i++) {
        h1 = (h1 * 26 + static_cast<long>(s[i] - 'a')) % mod1;
        h2 = (h2 * 26 + static_cast<long>(s[i] - 'a')) % mod2;
    }
    if (!mp1.count(h1)) mp1[h1] = unordered_set<long>();
    mp1[h1].insert(len - 1);
    if (!mp2.count(h1)) mp2[h2] = unordered_set<long>();
    mp2[h2].insert(len - 1);
    for (long i = len; i < n; i++) {
        h1 = (h1 * 26 - static_cast<long>(s[i - len] - 'a') * base1[len] + static_cast<long>(s[i] - 'a')) % mod1;
        h2 = (h2 * 26 - static_cast<long>(s[i - len] - 'a') * base2[len] + static_cast<long>(s[i] - 'a')) % mod2;
        if (mp1.count(h1) && mp2.count(h2)) {
            bool flag = false;
            for (long x : mp1[h1]) {
                if (!mp2[h2].count(x)) continue;
                flag = true;
                break;
            }
            if (flag) return s.substr(i - len + 1, len);
        }
        if (!mp1.count(h1)) mp1[h1] = unordered_set<long>();
        if (!mp2.count(h2)) mp2[h2] = unordered_set<long>();
        mp1[h1].insert(i);
        mp2[h2].insert(i);
    }
    return "";
}

string longestDupSubstring(string s) {
    srand(time(0));
    long n = s.size();
    long l = 1, r = n - 1;
    mod1 = (rand() % MOD) + MOD;
    mod2 = (rand() % MOD) + MOD;
    vector<long> base1(n + 1, 1);
    vector<long> base2(n + 1, 1);
    for (long i = 1; i <= n; i++) {
        base1[i] = (base1[i - 1] * 26) % mod1;
        base2[i] = (base2[i - 1] * 26) % mod2;
    }
    string ans = "";
    while (l < r) {
        long mid = (l + r + 1) / 2;
        string temp = check(s, base1, base2, mid);
        if (temp.size() > ans.size()) ans = temp;
        if (temp.size()) l = mid;
        else r = mid - 1;
    }
    return ans;
}

int main() {
    return 0;
}
