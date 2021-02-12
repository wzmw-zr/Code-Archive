/*************************************************************************
	> File Name: 2.LeetCode487.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月13日 星期六 00时08分05秒
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

int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size(), l = 0, r = 0, cnt = 0, ans = 0;
    while (r < n) {
        cnt += nums[r] ? 0 : 1;
        if (cnt > 1) {
            ans = max(ans, r - l);
            while (nums[l++]) {}
            cnt--;
        }
        r++;
    }
    ans = max(ans, r - l);
    return ans;
}

int main() {
    return 0;
}
