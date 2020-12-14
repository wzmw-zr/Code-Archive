/*************************************************************************
	> File Name: 1.LeetCode49.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月14日 星期一 07时46分32秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;
    for (string &s : strs) {
        string temp = s;
        sort(temp.begin(), temp.end());
        if (!mp.count(temp)) mp[temp] = vector<string>(0);
        mp[temp].push_back(s);
    }
    for (auto &&[_, second] : mp) ans.push_back(second);
    return ans;
}

int main() {
    string s;
    vector<string> strs;
    while (cin >> s) strs.push_back(s);
    auto ans = groupAnagrams(strs);
    for (auto &x : ans) {
        for (auto &y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}
