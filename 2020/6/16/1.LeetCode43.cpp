/*************************************************************************
	> File Name: 1.LeetCode43.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月16日 星期二 14时29分54秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void reverse(string &s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) swap(s[i], s[j]);
}

string multiply(string &s1, string &s2) {
    reverse(s1);
    reverse(s2);
    string res(s1.size() + s2.size(), 0);
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            res[i + j] += (s1[i] - '0') * (s2[j] - '0');
            if (res[i + j] >= 10) {
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }
    }
    for (int i = 0; i < res.size(); i++) {
        if (res[i] >= 10) {
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
    }
    if (res[res.size() - 1] == 0) res.pop_back();
    for (int i = 0; i < res.size(); i++) res[i] += '0';
    reverse(res);
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << multiply(s1, s2) << endl;
    return 0;
}
