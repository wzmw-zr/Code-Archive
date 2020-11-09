/*************************************************************************
	> File Name: 7.LeetCode493.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月09日 星期一 16时25分49秒
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

void merge(vector<long> &nums, long left, long right) {
    if (left >= right) return ;
    long mid = (left + right) / 2;
    long temp[right - left + 1];
    long x = left, y = mid + 1, ind = 0;
    while (x <= mid || y <= right) {
        if ((x <= mid) && (y > right || nums[x] <= nums[y])) 
            temp[ind++] = nums[x++];
        else 
            temp[ind++] = nums[y++];
    }
    for (long i = left, j = 0; i <= right; i++, j++) nums[i] = temp[j];
}

long merge_sort(vector<long> &nums, long left, long right) {
    if (left >= right) return 0;
    long mid = (left + right) / 2;
    long ans = 0;
    ans += merge_sort(nums, left, mid);
    ans += merge_sort(nums, mid + 1, right);
    long x = left, y = mid + 1;
    while (x <= mid && y <= right) {
        if (nums[x] <= (nums[y] * 2)) x++;
        else {
            ans += mid - x + 1;
            y++;
        }
    }
    merge(nums, left, right);
    return ans;
}

long reversePairs(vector<long>& nums) {
    return merge_sort(nums, 0, nums.size() - 1);
}

int main() {
    vector<long> nums;
    long x;
    while (cin >> x) nums.push_back(x);
    cout << reversePairs(nums) << endl;
    for (long x : nums) cout << x << " ";
    cout << endl;
    return 0;
}
