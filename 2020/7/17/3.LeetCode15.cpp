/*************************************************************************
	> File Name: 3.LeetCode15.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月17日 星期五 23时18分16秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

void find(int ind, vector<int> &nums, set<vector<int>> &st) {
    int l = ind + 1, r = nums.size() - 1;
    while (l < r) {
        int num = nums[l] + nums[r] + nums[ind];
        if (num == 0) {
            vector<int> tmp(3, 0);
            tmp[0] = nums[ind], tmp[1] = nums[l], tmp[2] = nums[r];
            st.insert(tmp);
            l++, r--;
        } else if (num > 0) r--;
        else l++;
    }
    return ;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    set<vector<int>> st;
    if (nums.size() < 3) return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        find(i, nums, st);
    }
    for (auto &x : st) res.push_back(x);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<int>> res = threeSum(nums);
    for (vector<int> &x : res) {
        for (int y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}
