/*************************************************************************
	> File Name: 3.LeetCode347.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月23日 星期六 14时14分27秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int cmp(iterator a, iterator b) {
    return a->second > b->second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int ,int> mp;
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++) mp[nums[i]]++;
    sort(mp.begin(), mp.end(), cmp);
    for (auto iter = mp.begin(), i = 0; i < k; i++, iter++) ret.push_back(mp->first);
    return ret;
}

int main() {
    return 0;
}
