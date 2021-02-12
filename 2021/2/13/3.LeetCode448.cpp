/*************************************************************************
	> File Name: 3.LeetCode448.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月13日 星期六 00时13分24秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), ind = 1;
    vector<int> ans;
    for (int i = 0; i < n; ) {
        if (ind == nums[i]) {
            while (i < n && nums[i] == ind) i++;
            ind++;
        } else if (ind < nums[i]) {
            while (ind < nums[i]) ans.push_back(ind++);
        }
    }
    while (ind <= n) ans.push_back(ind++);
    return ans;
}

int main() {
    return 0;
}
