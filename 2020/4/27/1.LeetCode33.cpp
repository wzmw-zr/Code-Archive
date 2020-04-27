/*************************************************************************
	> File Name: 1.LeetCode33.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月27日 星期一 07时18分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<unistd.h>
using namespace std;

int Rotate_Ind(vector<int> &nums, int left, int right) {
    cout << left << " " << right << endl;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (nums[mid] > nums[0]) left = mid + 1;
        else right = mid;
    }
    return left;
}

int GetInd(vector<int> &nums, int rotate_ind, int target) {
    int offset = nums.size() - rotate_ind;
    int len = nums.size();
    if (len == 0) return -1;
    int l = rotate_ind, r = (rotate_ind - 1 + len) % len, mid;
    while (((l + offset) % len) < ((r + offset) % len)) {
        if ((l < rotate_ind && r < rotate_ind) || (l >= rotate_ind && r >= rotate_ind)) mid = (l + r) >> 1;
        else {
            mid = ((r + len + l) >> 1) % len;
        }
        cout << l << " " << r << " " << mid << endl;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) l = (mid + 1 + len) % len;
        else r = (mid - 1 + len) % len;
        cout << l << " " << r << " " << mid << endl;
    }
    if (l == r && nums[l] == target) return l;
    return -1;
}

int search(vector<int> &nums, int target) {
    int rotate_ind = Rotate_Ind(nums, 0, nums.size() - 1);
    cout << rotate_ind << endl;
    int ind = GetInd(nums, rotate_ind, target);
    return ind;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        nums.push_back(data);
    }
    cout << search(nums, m) << endl;
    return 0;
}
