/*************************************************************************
	> File Name: 4.LeetCode76.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月29日 星期一 16时39分35秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool check(string s, string t) {
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++) mp[s[i]]++;
    for (int i = 0; i < t.size(); i++) {
        if (mp[t[i]] == 0) return false;
        mp[t[i]]--;
    }
    return true;
}

string minWindow(string s, string t) {
    int s_len = s.size(), t_len = t.size();
    for (int len = t_len; len <= s_len; len++) {
        for (int i = 0; i <= s_len - len; i++) {
            if (check(s.substr(i, len), t)) return s.substr(i, len);
        }
    }
    return "";
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;
    return 0;
}
