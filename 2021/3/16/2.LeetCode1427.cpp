/*************************************************************************
	> File Name: 2.LeetCode1427.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月16日 星期二 08时15分21秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void reverse_string(string &s, int l, int r) {
    while (l < r) {
        swap(s[l], s[r]);
        l++, r--;
    }
}

string stringShift(string s, vector<vector<int>>& shift) {
    int n = s.size();
    for (auto &x: shift) {
        int dir = x[0];
        int dis = x[1];
        dis %= n;
        if (dis == 0) continue;
        reverse_string(s, 0, n - 1);
        if (dir == 0) {
            reverse_string(s, 0, n - dis - 1);
            reverse_string(s, n - dis, n - 1);
        } else {
            reverse_string(s, 0, dis - 1);
            reverse_string(s, dis, n - 1);
        }
    }
    return s;
}

int main() {
    return 0;
}
