/*************************************************************************
	> File Name: 1.LeetCode500.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月31日 星期日 08时19分22秒
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

void init(vector<unordered_set<char>> &sts) {
    vector<string> strs = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    for (string s : strs) {
        unordered_set<char> st;
        for (char c : s) {
            st.insert(c);
            st.insert(c - 32);
        }
        sts.push_back(st);
    }
}

vector<string> findWords(vector<string>& words) {
    vector<unordered_set<char>> sts;
    vector<string> ans;
    init(sts);
    for (string s : words) {
        int flag = 0;
        int ind = 0;
        for (; ind < 3; ind++) {
            if (sts[ind].count(s[0])) break;
        }
        for (char c : s) {
            if (sts[ind].count(c)) continue;
            flag = 1;
            break;
        }
        if (!flag) ans.push_back(s);
    }
    return ans;
}

int main() {
    return 0;
}
