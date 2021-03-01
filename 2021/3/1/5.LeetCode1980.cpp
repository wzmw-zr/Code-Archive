/*************************************************************************
	> File Name: 5.LeetCode1980.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月01日 星期一 09时41分33秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> missingTwo(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int start = 1, ind = 0;
    vector<int> ans;
    while (ind < n) {
        if (start == nums[ind]) start++, ind++;
        else ans.push_back(start++);
    }
    int cnt = 2 - ans.size();
    for (int i = 0; i < cnt; i++) ans.push_back(start++);
    return ans;
}

int main() {
    return 0;
}
