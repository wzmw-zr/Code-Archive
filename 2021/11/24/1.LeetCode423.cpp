/*************************************************************************
	> File Name: 1.LeetCode423.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月24日 星期三 09时18分39秒
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
#include <tuple>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

string originalDigits(string s) {
    vector<int> cnts(26, 0);
    for (char c : s) cnts[c - 'a']++;
    vector<tuple<string, char, int>> s_nums = {{"zero", 'z', 0}, {"two", 'w', 2}, {"eight", 'g', 8}, {"three", 't', 3}, {"six", 'x', 6}, {"seven", 's', 7}, {"four", 'r', 4}, {"five", 'f', 5}, {"nine", 'i', 9}, {"one", 'o', 1}};
    vector<int> nums(10, 0);
    for (auto &&[str, ch, num] : s_nums) {
        if (!cnts[ch - 'a']) continue;
        int t = cnts[ch - 'a'];
        nums[num] += t;
        for (char c : str) cnts[c - 'a'] -= t;
    }
    string ans = "";
    for (int i = 0; i < 10; i++) {
        if (!nums[i]) continue;
        ans += string(nums[i], '0' + i);
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << originalDigits(s) << endl;
    return 0;
}
