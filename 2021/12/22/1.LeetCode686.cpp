/*************************************************************************
	> File Name: 1.LeetCode686.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月22日 星期三 08时56分19秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int kmp(string &text, string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> next(m, -1);
    for (int i = 1; i < m; i++) {
        int ind = next[i - 1];
        while (ind != -1 && pattern[ind + 1] != pattern[i]) ind = next[ind];
        next[i] = pattern[ind + 1] == pattern[i] ? ind + 1 : -1;
    }
    vector<int> match(n, -1);
    for (int i = 0; i < n; i++) {
        int ind = i == 0 ? -1 : match[i - 1];
        while (ind != -1 && pattern[ind + 1] != text[i]) ind = next[ind];
        match[i] = pattern[ind + 1] == text[i] ? ind + 1 : -1;
        if (match[i] == m - 1) return i + 1;
    }
    return -1;
}

int repeatedStringMatch(string a, string b) {
    int n = a.size(), m = b.size();
    int cnt = ceil(1.0 * m / n) * 2;
    string text = "";
    for (int i = 0; i < cnt; i++) text += a;
    int ind = kmp(text, b);
    if (ind == -1) return ind;
    return ceil(1.0 * ind / n);
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << repeatedStringMatch(a, b) << endl;
    return 0;
}
