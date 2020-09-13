/*************************************************************************
	> File Name: 4.kmp.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月13日 星期日 18时13分44秒
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
    int t_len = text.size();
    int p_len = pattern.size();
    vector<int> next(p_len + 5, 0);
    for (int i = 1; i < p_len; i++) {
        int j = next[i - 1];
        while ((j != 0) && (pattern[j] != pattern[i])) j = next[j - 1];
        if (pattern[j] == pattern[i]) next[i] = j + 1;
        else next[i] = 0;
    }
    for (int i = 0, j = 0; i < t_len; i++) {
        while ((j != 0) && (pattern[j] != text[i])) j = next[j - 1];
        if (pattern[j] == text[i]) j++;
        if (j == p_len) return true;
    }
    return false;
}

int main() {
    string pattern, text;
    cin >> pattern >> text;
    cout << (kmp(pattern, text) ? "Match" : "No Match") << endl;
    return 0;
}
