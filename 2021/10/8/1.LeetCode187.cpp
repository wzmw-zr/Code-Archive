/*************************************************************************
	> File Name: 1.LeetCode187.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月08日 星期五 08时26分07秒
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
    for (int i = 0; i < n - 10; i++) {
        string t = "";
        for (int j = i; j < i + 10; j++) t += s[j];
        mp[t]++;
    }
    vector<string> ans;
    for (auto [t, cnt] : mp) {
        if (cnt > 1) ans.push_back(t);
    }
    return ans;
}

int main() {
    return 0;
}
