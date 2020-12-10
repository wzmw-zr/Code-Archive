/*************************************************************************
	> File Name: 4.LeetCode1410.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月10日 星期四 17时10分38秒
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

void init(unordered_map<string, char> &mp) {
    mp["&quot;"] = '"';
    mp["&apos;"] = '\'';
    mp["&amp;"] = '&';
    mp["&gt;"] = '>';
    mp["&lt;"] = '<';
    mp["&frasl;"] = '/';
}

int check(string &text, int ind, unordered_map<string, char> &mp) {
    string s = "";
    for (int i = 0; i < 7 && text[i + ind] && text[i + ind] != ';'; i++) {
        s += text[i + ind];
    }
    s += ";";
    if (mp.count(s)) return s.size();
    return 0;
}

string entityParser(string text) {
    string ans = "";
    unordered_map<string, char> mp;
    init(mp);
    for (int i = 0; text[i]; ) {
        if (text[i] != '&') {
            ans += text[i++];
            continue;
        }
        int offset = check(text, i, mp);
        if (offset == 0) { 
            ans += text[i++];
            continue;
        }
        string temp = text.substr(i, offset);
        ans += mp[temp];
        i += offset;
    }
    return ans;
}

int main() {
    string text;
    getline(cin, text);
    cout << entityParser(text) << endl;
    return 0;
}
