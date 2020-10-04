/*************************************************************************
	> File Name: 1.kmp.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月04日 星期日 10时07分17秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

bool kmp(string pattern, string text) {
    int n = pattern.size();
    vector<int> next(n + 5, 0);
    for (int i = 1; i < n; i++) {
        int j = next[i - 1];
        while (j && pattern[j] != pattern[i]) j = next[j];
        if (pattern[j] == pattern[i]) j++;
        next[i] = j;
    }
    for (int i = 0, j = 0; text[i]; i++) {
        while (j && text[i] != pattern[j]) j = next[j];
        if (text[i] == pattern[j]) j++;
        if (j == n) return true;
    }
    return false;
}

int main() {
    string pattern, text;
    while (true) {
        cout << "pattern : ";
        cin >> pattern;
        cout << "text : ";
        cin >> text;
        cout << (kmp(pattern, text) ? "Match" : "Miss") << endl; 
    }
    return 0;
}
