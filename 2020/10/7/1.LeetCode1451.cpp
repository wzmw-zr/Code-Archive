/*************************************************************************
	> File Name: 1.LeetCode1451.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月07日 星期三 06时48分59秒
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

int longest_word_len(string &text) {
    int longest_len = INT32_MIN;
    for (int i = 0, len = 0; text[i]; ) {
        while (text[i + len] && text[i + len] != ' ') len++;
        longest_len = max(longest_len, len);
        i += len + 1;
    }
    return longest_len;
}

string arrangeWords(string text) {
    //int longest_len = longest_word_len(text);
    map<int, vector<string>> mp;
    string ans = "";
    for (int i = 0; text[i]; ) {
        string str = "";
        int len = 0;
        while (text[i + len] && text[i + len] != ' ') {
            str += text[i + len];
            len++;
        }
        i += len + 1;
        if (!mp.count(len)) mp[len] = vector<string>(0);
        mp[len].push_back(str);
    }
    for (auto &x : mp) {
        for (auto &y : x.second) ans += y + " ";
    }
    ans.erase(ans.end() - 1);
    return ans;
}

int main() {
    string text;
    getline(cin, text);
    cout << arrangeWords(text) << endl;
    return 0;
}
