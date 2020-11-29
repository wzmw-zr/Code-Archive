/*************************************************************************
	> File Name: 4.LeetCode5614.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月29日 星期日 10时47分09秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

int check(map<int, vector<int>>::iterator iter, map<int, vector<int>> &mp, int k) {
    int pre_place = -1;
    while (k && iter != mp.end()) {
        int n = iter->second.size();
        if (iter->second[n - 1] > pre_place) {
            pre_place = iter->second[0];
            k--;
        }
        iter++;
    }
    if (k) return 0;
    return 1;
}

vector<int> handle(map<int, vector<int>>::iterator iter, map<int, vector<int>> &mp, int k) {
    vector<int> ans;
    int pre_place = -1;
    while (k && iter != mp.end()) {
        int n = iter->second.size();
        if (iter->second[n - 1] > pre_place) {
            pre_place = iter->second[0];
            k--;
            ans.push_back(iter->first);
        }
        iter++;
    }
    return ans;
}

vector<int> mostCompetitive(vector<int>& nums, int k) {
    map<int, vector<int>> mp;
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!mp.count(nums[i])) mp[nums[i]] = vector<int>(0);
        mp[nums[i]].push_back(i);
    }
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        if (!check(iter, mp, k)) continue;
        ans = handle(iter, mp, k);
    }
    return ans;
}

int main() {
    return 0;
}
