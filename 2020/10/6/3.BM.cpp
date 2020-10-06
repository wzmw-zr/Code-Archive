/*************************************************************************
	> File Name: 3.BM.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月06日 星期二 17时59分12秒
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

void init(string &pattern, map<char, int> &mp, vector<int> &suf, map<int, int> &good_suf, int &longest_prefix) {
    int n = pattern.size();
    for (int i = 0; pattern[i]; i++) mp[pattern[i]] = n - i - 1;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        while (i - cnt >= 0 && pattern[i - cnt] == pattern[n - 1 - cnt]) cnt++;
        suf[i] = cnt;
        if (i - cnt + 1 == 0) longest_prefix = cnt;
    }
    for (int i = 0; i < n; i++) good_suf[suf[i]] = n - 1 - i;
}

bool bm(string text, string pattern) {
    int n = pattern.size();
    map<char, int> mp;
    map<int, int> good_suf;
    vector<int> suf(n, 0);
    int longest_prefix = 0;
    init(pattern, mp, suf, good_suf, longest_prefix);
    for (int i = 0; i < text.size() - n; ) {
        int end = i + n - 1, match_len = 0;
        while ((n - 1 - match_len >= 0) && pattern[n - 1 - match_len] == text[end]) end--, match_len++;
        if (match_len == n) return true;
        int bad_char_move = mp[text[end]] - match_len;
        int good_suf_move = good_suf.count(match_len) ? good_suf[match_len] : (match_len >= longest_prefix ? n - longest_prefix : n);
        i += max(bad_char_move, good_suf_move);
    }
    return false;
}

int main() {
    string text, pattern;
    cout << "text : ";
    cin >> text;
    cout << "pattern : ";
    cin >> pattern;
    cout << (bm(text, pattern) ? "Match" : "Miss") << endl;
    return 0;
}
