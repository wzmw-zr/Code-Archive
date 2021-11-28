/*************************************************************************
	> File Name: 1.LeetCode428.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月28日 星期日 08时04分31秒
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

vector<int> findAnagrams(string s, string p) {
    int n = s.size(), m = p.size();
    if (n < m) return {};
    vector<int> cnts_1(26, 0), cnts_2(26, 0);
    for (int i = 0; i < m; i++) cnts_2[p[i] - 'a']++;
    int l = 0, r = 0;
    while (r < n - 1 && r < m - 1) cnts_1[s[r] - 'a']++, r++;
    vector<int> ans;
    while (s[r]) {
        cnts_1[s[r] - 'a']++;
        if (cnts_1 == cnts_2) ans.push_back(r - m + 1);
        cnts_1[s[r - m + 1] - 'a']--;
        r++;
    }
    return ans;
}

int main() {
    string s, p;
    cin >> s >> p;
    auto ans = findAnagrams(s, p);
    for (auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
