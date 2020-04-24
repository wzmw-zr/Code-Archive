/*************************************************************************
	> File Name: 1.LeetCode.41.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月24日 星期五 07时09分53秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

void output(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    cout << endl;
}

int merge(vector<int> &nums, int l, int r) {
    if (l == r) return 0;
    int mid = (l + r) >> 1, res = 0;
    int temp[r -l + 1];
    int x = l, y = mid + 1, ind = 0;
    while (x <= mid || y <= r) {
        if (x <= mid && (y > r || nums[x] <= nums[y])) temp[ind++] = nums[x++];
        else {
            temp[ind++] = nums[y++];
            if (x <= mid) res += mid - x + 1;
        }
    }
    for (int i = 0; i < ind; i++) nums[l + i] = temp[i];
    cout << "merge : " << "l = " << l << " r = " << r << " ";
    output(nums);
    return res;
}

int merge_sort(vector<int> &nums, int l, int r) {
    if (l == r) return 0;   
    int mid = (l + r) >> 1, res = 0;
    res += merge_sort(nums, l, mid);
    res += merge_sort(nums, mid + 1, r);
    res += merge(nums, l, r);
    cout << "sort : " << " l = " << l << " r = " << r << " ";
    output(nums);
    return res;
}

int reversePairs(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    return merge_sort(nums, l, r);
}

int main() {
    int n;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    cout << reversePairs(nums) << endl;
    return 0;
}
