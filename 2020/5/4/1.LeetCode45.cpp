/*************************************************************************
	> File Name: 1.LeetCode45.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月04日 星期一 00时08分59秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int Jump(vector<int> &nums, int ind) {
    if (ind + nums[ind] >= nums.size() - 1) return 1;
    int max_end = ind, res_ind = ind;
    for (int i = 1; i <= nums[ind]; i++) {
        if (ind + i + nums[ind + i] > max_end) {
            res_ind = ind + i;
            max_end = ind + i + nums[ind + i];
        }
    }
    return Jump(nums, res_ind) + 1;
}

int jump(vector<int> &nums) {
    return Jump(nums, 0); 
}

int main() {
    int n, m;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> m;
        nums.push_back(m);
    }
    cout << jump(nums) << endl;
    return 0;
}
