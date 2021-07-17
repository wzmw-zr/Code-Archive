/*************************************************************************
	> File Name: 1.LeetCode2106.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月18日 星期日 00时07分45秒
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

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<map<char, int>, vector<string>> mp;
    for (string s : strs) {
        map<char, int> cnts;
        for (char c : s) cnts[c]++;
        if (!mp.count(cnts)) mp[cnts] = vector<string>{};
        mp[cnts].push_back(s);
    }
    vector<vector<string>> ans;
    for (auto &&[cnts, s_v] : mp) {
        sort(s_v.begin(), s_v.end());
        ans.push_back(s_v);
    }
    return ans;
}

int main() {
    return 0;
}
