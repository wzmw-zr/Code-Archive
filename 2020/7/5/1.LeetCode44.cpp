/*************************************************************************
	> File Name: 1.LeetCode44.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月05日 星期日 00时03分33秒
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

bool is_match(string s, string p, int s_ind, int p_ind) {
    cout << s_ind << " " << p_ind << endl;
    if (p_ind >= p.size() && s_ind < s.size()) return false;
    if (p_ind >= p.size() && s_ind >= s.size()) return true;
    if (p_ind < p.size() - 1 && s_ind >= s.size()) return false;
    if (p_ind == p.size() - 1 && s_ind == s.size() - 1) {
        if (p[p_ind] == '?' || p[p_ind] == '*') return true;
        if (p[p_ind] == s[s_ind]) return true;
        return false;
    }
    if (p[p_ind] == '?') return is_match(s, p, s_ind + 1, p_ind + 1);
    if (p[p_ind] >= 'a' && p[p_ind] <= 'z') {
        if (p[p_ind] == s[s_ind]) return is_match(s, p, s_ind + 1, p_ind + 1);
        return false;
    }
    int s_len = s.size(), res = 0;
    for (int i = 0; s_ind + i <= s_len; i++) {
        res = is_match(s, p, s_ind + i, p_ind + 1);
        cout << (res ? "yes" : "no") << endl;
        if (res) break;
    }
    return res;
}

bool isMatch(string s, string p) {
    return is_match(s, p, 0, 0);
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << s << endl << p << endl;
    cout << (isMatch(s, p) ? "True" : "False") << endl;
    return 0;
}
