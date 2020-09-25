/*************************************************************************
	> File Name: 5.kmp.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月25日 星期五 16时45分43秒
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

bool kmp(string text, string pattern) {
    int n = pattern.size();
    vector<int> next(n + 5, 0);
    for (int i = 1; i < n; i++) {
        int j = next[i - 1];
        while (j && pattern[j] != pattern[i + j]) j = next[j];
        if (pattern[j] == pattern[i + j]) next[i] = j + 1;
    }
    for (int i = 0, j = 0; i < text.size(); i++) {
        while (j && pattern[j] != text[i + j]) j = next[j];
        if (pattern[j] == text[i + j]) j++;
        if (j == n) return true;
    }
    return false;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    cout << (kmp(text, pattern) ? "Match" : "Miss") << endl;
    return 0;
}
