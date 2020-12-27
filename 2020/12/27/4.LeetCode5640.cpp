/*************************************************************************
	> File Name: 4.LeetCode5640.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月27日 星期日 11时01分28秒
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

int binary_search(vector<int> &nums, int x) {
    int l = -1, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (nums[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    sort(nums.begin(), nums.end());
    vector<int> ans;
    for (auto &x : queries) {
        int ind = binary_search(nums, x[1]);
        if (ind == -1) {
            ans.push_back(-1);
            continue;
        }
        int temp = x[0] ^ nums[0];
        for (int i = 0; i <= ind; i++) temp = max(temp, x[0] ^ nums[i]);
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    return 0;
}
