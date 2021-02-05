/*************************************************************************
	> File Name: 5.LeetCode1493.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月05日 星期五 23时03分51秒
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

int longestSubarray(vector<int>& nums) {
    int n = nums.size(), l = 0, r = 0, ans = 0, cnt = 0;
    while (r < n) {
        cnt += !nums[r++];
        while (cnt > 1) cnt -= !nums[l++];
        ans = max(ans, r - l - 1);
    }
    return ans;
}

int main() {
    return 0;
}
