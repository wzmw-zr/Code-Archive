/*************************************************************************
	> File Name: 1.Sunday.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月14日 星期一 09时03分46秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

bool Sunday(string pattern, string text) {
    if (pattern.size() > text.size()) return false;
    map<char, int> mp;
    for (int i = pattern.size() - 1, j = 0; i >= 0; i--, j++) {
        if (mp.find(pattern[i]) != mp.end()) continue;
        mp[pattern[i]] = j;
    }
    for (int i = 0; i < text.size() - pattern.size(); ) {
        int j = 0, k = i;
        for (; (j < pattern.size()) && (k < text.size()) ; j++, k++) {
            if (text[k] == pattern[j]) continue;
        }
        if ((j == pattern.size()) && (pattern[j - 1] == text[k - 1])) return true;
        if (mp.find(text[i + pattern.size()]) != mp.end()) i += mp[text[i + pattern.size()]] + 1;
        else i += pattern.size() + 1;
    }
    return false;
}

int main() {
    string pattern, text;
    cin >> pattern >> text;
    cout << pattern << endl << text << endl;
    cout << (Sunday(pattern, text) ? "Match" : "No Match") << endl;
    return 0;
}
