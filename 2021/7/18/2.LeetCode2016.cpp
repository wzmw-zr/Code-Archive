/*************************************************************************
	> File Name: 2.LeetCode2016.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月18日 星期日 00时15分26秒
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
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
        string temp = s;
        sort(temp.begin(), temp.end());
        if (!mp.count(temp)) mp[temp] = vector<string>{};
        mp[temp].push_back(s);
    }
    vector<vector<string>> ans;
    for (auto &&[cnts, s] : mp) {
        sort(s.begin(), s.end());
        ans.push_back(s);
    }
    return ans;
}

int main() {
    return 0;
}
