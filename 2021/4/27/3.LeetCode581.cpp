/*************************************************************************
	> File Name: 3.LeetCode581.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月27日 星期二 00时36分40秒
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

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    int l = 0, r = n - 1;
    while (l < r && temp[l] == nums[l]) l++;
    while (l < r && temp[r] == nums[r]) r--;
    if (l == r) return 0;
    return r - l + 1;
}

int main() {
    return 0;
}
