/*************************************************************************
	> File Name: 4.LeetCode398.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月19日 星期五 19时53分26秒
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
#include<ctime>
using namespace std;

class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) : nums(nums) {
        srand(time(0));
    }

    int pick(int target) {
        int n = nums.size();
        int flag = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != target) continue;
            if (!flag) {
                flag = 1;
                ans = i;
            }
            if ((rand() % (i + 1)) == 0) ans = i;
        }
        return ans;
    }
};

int main() {
    return 0;
}
