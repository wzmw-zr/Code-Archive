/*************************************************************************
	> File Name: 4.LeetCode2150.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月27日 星期四 08时55分34秒
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

vector<int> findLonely(vector<int>& nums) {
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int x : nums) mp[x]++;
    for (auto &&[x, cnt] : mp) {
        if (cnt != 1) continue;
        if (!mp.count(x - 1) && !mp.count(x + 1)) {
            ans.push_back(x);
        }
    }
    return ans;
}

int main() {
    return 0;
}
