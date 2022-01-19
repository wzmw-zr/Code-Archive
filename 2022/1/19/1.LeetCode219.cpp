/*************************************************************************
	> File Name: 1.LeetCode219.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月19日 星期三 09时13分53秒
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

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    int ind = 0;
    unordered_map<int, int> mp;
    while (ind < n || ind <= k) {
        if (ind == n) return false;
        if (mp.count(nums[ind])) return true;
        mp[nums[ind]]++;
        if (ind >= k) mp.erase(nums[ind - k]);
        ind++;
    }
    return false;
}

int main() {
    return 0;
}
