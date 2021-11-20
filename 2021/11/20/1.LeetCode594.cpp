/*************************************************************************
	> File Name: 1.LeetCode594.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月20日 星期六 08时17分11秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int findLHS(vector<int> &nums) {
    map<int, int> mp;
    for (int x : nums) mp[x]++;
    int ans = 0;
    for (auto &&[x, cnt] : mp) {
        if (!mp.count(x - 1)) continue;
        ans = max(ans, mp[x] + mp[x - 1]);
    }
    return ans;
}

int main() {
    return 0;
}
