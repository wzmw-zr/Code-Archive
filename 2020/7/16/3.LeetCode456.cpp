/*************************************************************************
	> File Name: 3.LeetCode456.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月16日 星期四 15时05分34秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

bool merge(vector<int> &nums, int l, int r) {
    bool ret = false;
    int tmp[r - l + 1];
    int x = l, mid = (l + r) >> 1, y = mid + 1, ind = 0;
    while (x <= mid || y <= r) {
        if (x <= mid && (y > r || nums[x] <= nums[y])) tmp[ind++] = nums[x++];
        else {
            if (x <= mid && x != l) ret = true;
            tmp[ind++] = nums[y++];   
        }
    }
    for (int i = 0; i < r - l + 1; i++) nums[l + i] = tmp[i];
    return ret;
}

bool merge_sort(vector<int> &nums, int l, int r) {
    if (l >= r) return false;
    int mid = (l + r) >> 1;
    bool res = false;
    res |= merge_sort(nums, l, mid);
    res |= merge_sort(nums, mid + 1, r);
    res |= merge(nums, l, r);
    return res;
}

bool find132pattern(vector<int>& nums) {
    int len = nums.size();
    return merge_sort(nums, 0, len - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << (find132pattern(nums) ? "True" : "False") << endl;
    return 0;
}
