/*************************************************************************
	> File Name: 3.LeetCode5747.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月02日 星期日 10时33分01秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

// long type will out of range, so choose python to solve this question.
bool dfs(string &s, int ind, int pre_num) {
    if (!s[ind]) return true;
    bool ans = false;
    for (int i = 0; s[ind + i]; i++) {
        int num = stoi(s.substr(ind, i + 1));
        if (pre_num == num + 1) ans |= dfs(s, ind + i + 1, num);
    }
    return ans;
}

bool splitString(string s) {
    int ind = 0;
    bool ans = false;
    for (ind = 0; s[ind + 1] && !ans; ind++) {
        int num = stoi(s.substr(0, ind + 1));
        ans |= dfs(s, ind + 1, num);
    }
    return ans;
}

int main() {
    return 0;
}
