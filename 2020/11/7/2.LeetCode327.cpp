/*************************************************************************
	> File Name: 2.LeetCode327.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月07日 星期六 08时38分25秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

void merge(vector<long> &nums, int left, int right) {
    if (left >= right) return ;
    int temp[right - left + 1];
    int mid = (left + right) / 2;
    int x = left, y = mid + 1, ind = 0;
    while (x <= mid || y <= right) {
        if (x <= mid && (y > right || nums[x] <= nums[y])) temp[ind++] = nums[x++];
        else temp[ind++] = nums[y++];
    }
    for (int i = left, j = 0; i <= right; i++, j++) nums[i] = temp[j];
}

void merge_sort(vector<long> &nums, int left, int right, int &lower, int &upper, int &cnt) {
    if (left == right) return ;
    int mid = (left + right) / 2;
    merge_sort(nums, left, mid, lower, upper, cnt);
    merge_sort(nums, mid + 1, right, lower, upper, cnt);
    int l = mid + 1, r = mid + 1;
    for (int i = left; i <= mid; i++) {
        while ((l <= right) && (nums[l] - nums[i]) < lower) l++;
        while ((r <= right) && (nums[r] - nums[i]) <= upper) r++;
        cnt += r - l;
    }
    merge(nums, left, right);
}

int countRangeSum(vector<int>& nums, int lower, int upper) {
    int cnt = 0;
    vector<long> num;
    num.push_back(0);
    for (auto &x : nums) num.push_back(x);
    for (int i = 1; i < num.size(); i++) num[i] += num[i - 1];
    merge_sort(num, 0, num.size() - 1, lower, upper, cnt);
    return cnt;
}

int main() {
    return 0;
}
