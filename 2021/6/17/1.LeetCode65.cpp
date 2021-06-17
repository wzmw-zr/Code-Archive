/*************************************************************************
	> File Name: 1.LeetCode65.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月17日 星期四 09时22分54秒
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
using namespace std;

bool is_interger(string s, bool enable_pos_neg) {
    if (s.size() == 0) return false;
    int ind = 0;
    if (enable_pos_neg) {
        if ((s[0] == '+') || (s[0] == '-')) ind++;
        int flag = 0;
        while (s[ind] && (s[ind] >= '0') && (s[ind] <= '9')) {
            ind++;
            flag = 1;
        }
        if (!flag) return false;
        return s[ind] ? false : true;
    }
    while (s[ind] && (s[ind] >= '0') && (s[ind] <= '9')) ind++;
    return s[ind] ? false : true;
}

bool has_dot(string s) {
    for (char c : s) {
        if (c == '.') return true;
    }
    return false;
}

bool is_float(string s) {
    int n = s.size();
    if (n == 0) return false;
    if ((s[0] == '+') || (s[0] == '-')) {
        int ind = s.find('.');
        if (ind == 1) return is_interger(s.substr(2), false);
        if (ind == (n - 1)) return is_interger(s.substr(0, n - 1), true);
        // cout << s.substr(0, ind) << endl;
        // cout << s.substr(ind + 1) << endl;
        return is_interger(s.substr(0, ind), true) && is_interger(s.substr(ind + 1), false);
    }
    int ind = s.find('.');
    if (ind == 0) return is_interger(s.substr(1), false);
    if (ind == (n - 1)) return is_interger(s.substr(0, n - 1), false);
    return is_interger(s.substr(0, ind), false) && is_interger(s.substr(ind + 1), false);
}

bool has_e_or_E(string s) {
    for (char c : s) {
        if ((c == 'e') || (c == 'E')) return true;
    }
    return false;
}

bool is_scientific_format(string s) {
    int ind = s.find('e');
    if (ind != string::npos) {
        string left = s.substr(0, ind);
        string right = s.substr(ind + 1);
        return (is_float(left) || is_interger(left, true)) && is_interger(right, true);
    }
    ind = s.find('E');
    string left = s.substr(0, ind);
    string right = s.substr(ind + 1);
    return (is_float(left) || is_interger(left, true)) && is_interger(right, true);
}

bool isNumber(string s) {
    unordered_set<char> valid_symbol;
    for (char c = '0'; c <= '9'; c++) valid_symbol.insert(c);
    valid_symbol.insert('+');
    valid_symbol.insert('-');
    valid_symbol.insert('e');
    valid_symbol.insert('E');
    valid_symbol.insert('.');

    for (char c : s) {
        if (valid_symbol.count(c)) continue;
        return false;
    }

    if (has_e_or_E(s)) return is_scientific_format(s);
    if (has_dot(s)) return is_float(s);
    return is_interger(s, true);
}

int main() {
    string s;
    cin >> s;
    cout << (isNumber(s) ? "True" : "False") << endl;
    return 0;
}
