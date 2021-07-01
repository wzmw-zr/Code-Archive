/*************************************************************************
	> File Name: 2.LeetCode22.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月02日 星期五 00时04分34秒
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

unordered_map<int, vector<string>> mp;

vector<string> generateParenthesis(int n) {
    if (mp.count(n)) return mp[n];
    if (n == 0) return mp[0] = vector<string>({""});
    if (n == 1) return mp[1] = vector<string>({"()"});
    unordered_set<string> st;
    vector<string> ans;
    for (int i = 0; i <= (n - 1); i++) {
        auto left = generateParenthesis(i);
        auto right = generateParenthesis(n - 1 - i);
        for (auto l : left) {
            for (auto r : right) {
                st.insert("()" + l + r);
                st.insert(l + "()" + r);
                st.insert(l + r + "()");
                st.insert("(" + l + ")" + r);
                st.insert(l + "(" + r + ")");
                st.insert("(" + l + r + ")");
            }
        }
    }
    for (string s : st) ans.push_back(s);
    sort(ans.begin(), ans.end());
    return mp[n] = ans;
}

int main() {
    return 0;
}
