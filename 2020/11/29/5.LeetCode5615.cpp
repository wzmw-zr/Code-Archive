/*************************************************************************
	> File Name: 5.LeetCode5615.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月29日 星期日 10时58分24秒
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

int get_change_cnt(vector<int> &nums, int limit, int x) {
    int n = nums.size();
    int cnt = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (nums[i] + nums[j] == x) continue;
        if (nums[i] >= x && nums[j] >= x) cnt += 2;
        else if ((nums[i] + limit < x) && (nums[j] + limit < x)) cnt += 2;
        else cnt++;
    }
    return cnt;
}

int minMoves(vector<int>& nums, int limit) {
    unordered_set<int> st;
    int n = nums.size();
    for (int i = 0, j = n - 1; i < j; i++, j--) st.insert(nums[i] + nums[j]);
    int ans = INT32_MAX;
    for (int x : st) {
        int cnt = get_change_cnt(nums, limit, x);
        ans = min(ans, cnt);
    }
    return ans;
}

int main() {
    return 0;
}
