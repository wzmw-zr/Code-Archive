/*************************************************************************
	> File Name: 4.BM.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月06日 星期二 19时09分19秒
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

string pattern, text;

void init(string &pattern, map<char, int> &bad_char_mp, vector<int> &suf, vector<int> &good_suf, map<int, int> &good_suf_mp) {
    int n = pattern.size();
    int longest_prefix = 0;
    for (int i = 0; i < n; i++) bad_char_mp[pattern[i]] = n - 1 - i;
    for (int i = 0; i < n; i++) {
        int len = 0;
        while ((i - len >= 0) && pattern[i - len] == pattern[n - 1 - len]) len++;
        suf[i] = len;
        if (i - len < 0) longest_prefix = len;
    }
    for (int i = 0; i < n; i++) good_suf_mp[suf[i]] = n - 1 - i;
    for (int i = 0; i < n; i++) {
        if (good_suf_mp.count(i)) continue;
        if (i >= longest_prefix) good_suf_mp[i] = n - longest_prefix;
        else good_suf_mp[i] = n;
    }
    for (int i = 0; i < n; i++) good_suf[i] = good_suf_mp[n - 1 - i];
}

int main() {
    cout << "pattern : ";
    cin >> pattern;
    cout << "text : ";
    cin >> text;
    int n = pattern.size();
    map<char, int> bad_char_mp;
    vector<int> suf(n), good_suf(n);
    map<int, int> good_suf_mp;
    init(pattern, bad_char_mp, suf, good_suf, good_suf_mp);
    //cout << "=======================================================" << endl;
    for (auto &x : bad_char_mp) cout << x.first << " " << x.second << endl;
    for (int i = 0; i < n; i++) cout << suf[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << good_suf[i] << " ";
    cout << endl;
    //for (auto &x : good_suf_mp) cout << x.first << " " << x.second << endl;
    int i = 0, len = text.size();
    for (i = 0; i < len - n; ) {
        int match_len = 0;
        while (match_len < n && text[i + n - 1 - match_len] == text[n - 1 - match_len]) match_len++;
        if (match_len == n) {
            cout << "Match" << endl;
            return 0;
        }
        int bad_char_move = (bad_char_mp.count(text[i + n - 1 - match_len]) ? bad_char_mp[text[i + n - 1 - match_len]] - match_len : n);
        int good_suf_move = good_suf_mp[i + n - 1 - match_len];
        i += max(bad_char_move, good_suf_move);
    }
    cout << "Miss" << endl;
    return 0;
}
