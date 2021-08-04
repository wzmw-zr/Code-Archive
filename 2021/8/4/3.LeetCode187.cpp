/*************************************************************************
	> File Name: 3.LeetCode187.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月04日 星期三 10时37分04秒
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

vector<string> findRepeatedDnaSequences(string s) {
    int n = s.size();
    unordered_map<string, int> mp;
    vector<string> ans;
    if (n <= 10) return ans;
    string p = s.substr(0, 10);
    mp[p] = 1;
    for (int i = 10; s[i]; i++) {
        p.erase(p.begin()); 
        p += s[i];
        mp[p]++;
    }
    for (auto &&[x, cnt] : mp) {
        if (cnt <= 1) continue;
        ans.push_back(x);
    }
    return ans;
}

int main() {
    return 0;
}
