/*************************************************************************
	> File Name: 1.LeetCode76.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月23日 星期六 07时08分46秒
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> s_mp, t_mp;
    for (int i = 0; t[i]; i++) t_mp[t[i]] += 1;
    for (int i = 0; s[i]; i++) {
        if (t_mp.find(s[i]) != t_mp.end()) {
            s_mp[s[i]] += 1;
        }
    }
    for (auto i = t_mp.begin(); i != t_mp.end(); i++) {
        if (s_mp.find(i->first) != s_mp.end() && s_mp[i->first] >= i->second) continue;
        return "";
    }
    int l = 0, r = s.size() - 1;
    while (r - l + 1 > t.size()) {
        while (s_mp.find(s[l]) == s_mp.end()) l++;
        while (s_mp.find(s[r]) == s_mp.end()) r--;
        if (s_mp[s[l]] == t_mp[s[l]] && s_mp[s[r]] == t_mp[s[r]]) break;
        if (s_mp[s[l]] > t_mp[s[l]]) l++, s_mp[s[l]]--;
        if (s_mp[s[r]] > t_mp[s[r]]) r--, s_mp[s[r]]--;
    }
    return "";
}

int main() {
    string s, t;
    cin >> s >> t;
    return 0;
}
