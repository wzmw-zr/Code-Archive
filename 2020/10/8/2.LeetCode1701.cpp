/*************************************************************************
	> File Name: 2.LeetCode1701.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月08日 星期四 13时28分04秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string reverseWords(string s) {
    vector<string> words;
    string ans = "";
    int ind = 0, n = s.size();
    for (ind = 0; ind < n; ) {
        string temp = "";
        while (s[ind] && s[ind] == ' ') ind++;
        while (s[ind] && s[ind] != ' ') temp += s[ind++];
        if (temp != "") words.push_back(temp);
    }
    for (int i = words.size() - 1; i >= 0; i--) ans += words[i] + " ";
    ans.erase(ans.end() - 1);
    return ans;
}

int main() {
    string s;
    getline(cin, s);
    cout << reverseWords(s) << endl;
    return 0;
}
