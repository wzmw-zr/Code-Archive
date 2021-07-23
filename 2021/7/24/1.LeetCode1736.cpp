/*************************************************************************
	> File Name: 1.LeetCode1736.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月24日 星期六 01时09分15秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(string &s) {
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    if ((hour >= 24) || (minute >= 60)) return false;
    return true;
}

void dfs(string &s, string &time, int ind, string &ans) {
    if (ind == 5) {
        if (check(s)) ans = max(ans, s);
        return ;
    }
    if (time[ind] != '?') {
        s[ind] = time[ind];
        dfs(s, time, ind + 1, ans);
    } else {
        for (char c = '0'; c <= '9'; c++) {
            s[ind] = c;   
            dfs(s, time, ind + 1, ans);
        }
    }
}

string maximumTime(string time) {
    string s(5, ' ');
    string ans = "00:00";
    dfs(s, time, 0, ans);
    return ans;
}

int main() {
    return 0;
}
