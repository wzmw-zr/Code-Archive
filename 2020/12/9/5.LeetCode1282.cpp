/*************************************************************************
	> File Name: 5.LeetCode1282.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月09日 星期三 18时10分03秒
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

void handle(vector<vector<int>> &ans, int n, vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len; ) {
        vector<int> temp;
        for (int j = 0; j < n; j++) temp.push_back(nums[i + j]);
        ans.push_back(temp);
        i += n;
    }
}

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    int n = groupSizes.size();
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        if (!mp.count(groupSizes[i])) mp[groupSizes[i]] = vector<int>(0);
        mp[groupSizes[i]].push_back(i);
    }
    vector<vector<int>> ans;
    for (auto &&[num, nums] : mp) handle(ans, num, nums);
    return ans;
}

int main() {
    return 0;
}
