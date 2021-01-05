/*************************************************************************
	> File Name: 1.LeetCode830.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月05日 星期二 12时07分58秒
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

vector<vector<int>> largeGroupPositions(string s) {
    int left = 0, right = 0;
    vector<vector<int>> ans;
    while (s[right]) {
        while (s[right] && s[left] == s[right]) right++;
        if (right - left >= 3) ans.push_back(vector<int>({left, right - 1}));
        left = right;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    auto ans = largeGroupPositions(s);
    for (auto &x : ans) {
        for (auto &y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}
