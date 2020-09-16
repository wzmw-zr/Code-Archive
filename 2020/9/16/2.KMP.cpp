/*************************************************************************
	> File Name: 2.KMP.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月16日 星期三 08时14分43秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

bool kmp(string pattern, string text) {
    int p_len = pattern.size(), t_len = text.size();
    if (p_len > t_len) return false;
    vector<int> next(p_len + 5, 0);
    for (int i = 1; i < p_len; i++) {
        int s = next[i - 1];
        while (s && pattern[s] != pattern[i]) s = next[s];
        if (pattern[s] == pattern[i]) next[i] = s + 1;
    }
    for (int i = 0, j = 0; text[i]; i++) {
        while (j && pattern[j] != text[i]) j = next[j];
        if (pattern[j] == text[i]) j++;
        if (j == p_len) return true;
    }
    return false;
}

int main() {
    string pattern, text;
    while (cin >> pattern >> text) {
        cout << (kmp(pattern, text) ? "Match" : "Miss") << endl;
    }
    return 0;
}
