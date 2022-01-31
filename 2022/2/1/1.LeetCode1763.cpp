/*************************************************************************
	> File Name: 1.LeetCode1763.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月01日 星期二 00时12分16秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

string longestNiceSubstring(string s) {
    int n = s.size();
    string ans = "";
    auto check = [](string &str) -> bool {
        unordered_set<char> st;
        for (char c : str) {
            st.insert(c);
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (!st.count(c) && !st.count(c - 32)) {
                continue;
            }
            if (st.count(c) && st.count(c - 32)) {
                continue;
            }
            return false;
        }
        return true;
    };
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string temp = s.substr(i, j - i + 1);
            if (check(temp) && ans.size() < temp.size()) {
                ans = temp;
            }
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << longestNiceSubstring(s) << endl;
    return 0;
}
