/*************************************************************************
	> File Name: 4.LeetCode151.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月29日 星期一 01时30分27秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string reverseWords(string s) {
    reverse(s.begin(), s.end());
    string ans = "";
    int ind = 0;
    for (int i = 0; s[i]; ) {
        while (s[i] && s[i] == ' ') i++;
        string temp = "";
        while (s[i] && s[i] != ' ') temp += s[i++];
        if (temp.size() == 0) continue;
        if (ind) ans += ' ';
        ans += temp;
        ind = 1;
    }
    return ans;
}

int main() {
    return 0;
}
