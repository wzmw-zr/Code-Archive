/*************************************************************************
	> File Name: 3.LeetCode1324.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月08日 星期四 14时05分00秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> printVertically(string s) {
    vector<string> words;
    int i = 0, n = s.size(), len = 0;
    for (i = 0; i < n; ) {
        string word = "";
        while (s[i] && s[i] == ' ') i++;
        while (s[i] && s[i] != ' ') word += s[i++];
        if (word != "") {
            len = max(len, (int) word.size());
            words.push_back(word);
        }
    } 
    vector<string> ans(len);
    for (i = 0; i < len; i++) {
        for (int j = 0; j < words.size(); j++) {
            if (i >= words[j].size()) ans[i] += " ";
            else ans[i] += words[j][i];
        }
        while (ans[i].size() && ans[i][ans[i].size() - 1] == ' ') ans[i].erase(ans[i].end() - 1);
    }
    return ans;
}

int main() {
    string s;
    getline(cin, s);
    vector<string> ans = printVertically(s);
    for (string &x : ans) cout << x << endl;
    return 0;
}
