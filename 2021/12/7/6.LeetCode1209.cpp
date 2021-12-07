/*************************************************************************
	> File Name: 6.LeetCode1209.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月07日 星期二 12时12分09秒
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

using PCI = pair<char, int>;

string removeDuplicates(string s, int k) {
    vector<PCI> st;
    for (char c : s) {
        if (st.size() == 0 || st.rbegin()->first != c) st.push_back(PCI(c, 1));
        else {
            if (++(st.rbegin()->second) == k) st.pop_back();
        }
    }
    string ans = "";
    for (auto &&[c, cnt] : st) ans += string(cnt, c);
    return ans;
}

int main() {
    return 0;
}
