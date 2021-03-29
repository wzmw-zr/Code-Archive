/*************************************************************************
	> File Name: 5.LeetCode856.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月29日 星期一 21时40分19秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int scoreOfParentheses(string &s, int l, int r) {
    if (l > r) return 0;
    if (l + 1 == r) return 1;
    int cnt = 1;
    int i = l + 1;
    for (i = l + 1; i <= r; i++) {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt == 0) break;
    }
    if (i == r) return 2 * scoreOfParentheses(s, l + 1, r - 1);
    return scoreOfParentheses(s, l, i) + scoreOfParentheses(s, i + 1, r);
}

int scoreOfParentheses(string S) {
    int n = S.size();
    return scoreOfParentheses(S, 0, n - 1);
}


int main() {
    string s;
    cin >> s;
    cout << scoreOfParentheses(s) << endl;
    return 0;
}
