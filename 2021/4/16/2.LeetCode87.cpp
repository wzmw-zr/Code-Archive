/*************************************************************************
	> File Name: 2.LeetCode87.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月16日 星期五 00时36分27秒
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

bool check(string &s1, string &s2) {
    vector<int> cnt(26, 0);
    for (char c : s1) cnt[c - 'a']++;
    for (char c : s2) {
        if (cnt[c - 'a']-- == 0) return false;
    }
    return true;
}

bool is_same_vec(vector<int> &cnt1, vector<int> &cnt2) {
    int n = cnt1.size();
    for (int i = 0; i < n; i++) {
        if (cnt1[i] - cnt2[i]) return false;
    }
    return true;
}

unordered_map<string, bool> mp;

bool isScramble(string s1, string s2) {
    if (!check(s1, s2)) return false;
    if (s1 == s2) return true;
    if (s1.size() == 1) return true;
    string temp1 = s1 + " " + s2;
    string temp2 = s2 + " " + s1;
    if (mp.count(temp1)) return mp[temp1];
    if (mp.count(temp2)) return mp[temp2];
    bool ans = false;
    int n = s1.size();
    vector<int> cnt(26, 0);
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (char c : s1) cnt[c - 'a']++;
    for (int i = 0; i < n - 1 && !ans; i++) {
        cnt1[s1[i] - 'a']++;
        cnt2[s2[i] - 'a']++;
        if (is_same_vec(cnt1, cnt2))
            ans |=
                isScramble(s1.substr(i + 1), s2.substr(i + 1))
                &
                isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1));
    }
    if (ans) mp[temp1] = true, mp[temp2] = true;
    if (ans) return ans;
    for (int &x : cnt1) x = 0;
    for (int &x : cnt2) x = 0;
    for (int i = 0; i < n - 1 && !ans; i++) {
        cnt1[s1[i] - 'a']++;
        cnt2[s2[n - 1 - i] - 'a']++;
        if (is_same_vec(cnt1, cnt2))
            ans |=
                isScramble(s1.substr(i + 1), s2.substr(0, n - i - 1))
                &
                isScramble(s1.substr(0, i + 1), s2.substr(n - i - 1));
    }
    mp[temp1] = ans, mp[temp2] = ans;
    return ans;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (isScramble(s1, s2) ? "True" : "False") << endl;
    return 0;
}
