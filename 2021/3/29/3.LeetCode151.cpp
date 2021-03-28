/*************************************************************************
	> File Name: 3.LeetCode151.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月29日 星期一 01时17分17秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string reverseWords(string s) {
    vector<string> str;
    string ans = "";
    for (int i = 0; s[i]; ) {
        while (s[i] && s[i] == ' ') i++;
        string temp = "";
        while (s[i] && s[i] != ' ') temp += s[i++];
        str.push_back(temp);
    }
    int n = str.size();
    for (int i = 0; i < n; i++) {
        if (i) ans += ' ';
        ans += str[n - i - 1];
    }
    return ans;
}

int main() {
    string s;
    getline(cin, s);
    cout << reverseWords(s) << endl;
    return 0;
}
