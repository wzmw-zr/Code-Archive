/*************************************************************************
	> File Name: 5.LeetCode1209.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月07日 星期二 11时02分31秒
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

string removeDuplicates(string s, int k) {
    string ans = "";
    unordered_map<char, int> mp;
    for (char c : s) {
        ans.push_back(c);
        mp[c]++;
        if (ans.size() > k) {
            char t = ans[ans.size() - k - 1];
            if (!(--mp[t])) mp.erase(t);
        }
        while (ans.size() >= k) {
            if (mp.size() == 1) {
                for (int i = 0; i < k; i++) ans.pop_back();
                mp.erase(mp.begin());
                int n = ans.size();
                int t = min(n, k);
                for (int i = n - 1; i >= n - t; i--) mp[ans[i]]++;
            } else break;
        }
    }
    return ans;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << removeDuplicates(s, k) << endl;
    return 0;
}
