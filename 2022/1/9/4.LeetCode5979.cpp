/*************************************************************************
	> File Name: 4.LeetCode5979.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月09日 星期日 20时45分10秒
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

using PII = pair<int, int>;

int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int n = plantTime.size();
    vector<PII> nums;
    for (int i = 0; i < n; i++) nums.push_back(PII(plantTime[i], growTime[i]));
    auto cmp = [](PII &a, PII &b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    };
    sort(nums.begin(), nums.end(), cmp);
    int ans = 0;
    int day = 0;
    for (int i = 0; i < n; i++) {
        day += nums[i].first;
        ans = max(ans, day + nums[i].second);
    }
    return ans;
}

int main() {
    return 0;
}
