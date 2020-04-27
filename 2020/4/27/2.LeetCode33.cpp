/*************************************************************************
	> File Name: 2.LeetCode33.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月27日 星期一 09时10分22秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<unistd.h>
using namespace std;

struct Node {
    int ind, val;
};

int Rotate_Ind(vector<int> &nums, int left, int right) {
    while (left < right) {
        int mid = (left + right) >> 1;
        if (nums[mid] >= nums[0]) left = mid + 1;
        else right = mid;
    }
    return left;
}

int GetIndex(vector<int> &nums, int rotate_ind, int target) {
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

int GetInd(vector<Node> &data, int target) {
    int l = 0, r = data.size() - 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (data[mid].val == target) return data[mid].ind;
        if (data[mid].val < target) l = mid + 1;
        else r = mid - 1;
    }
    if (data[l].val == target) return data[l].ind;
    return -1;
}

int search(vector<int> &nums, int target) {
    if (nums.size() == 0) return -1;
    int rotate_ind = Rotate_Ind(nums, 0, nums.size() - 1);
    cout << rotate_ind << endl;
    vector<Node> data;
    for (int i = rotate_ind; i < nums.size(); i++) {
        data.push_back({i, nums[i]});
    }
    for (int i = 0; i < rotate_ind; i++) {
        data.push_back({i, nums[i]});
    }
    for (int i = 0; i < nums.size(); i++) {
        cout << data[i].val << " ";
    }
    cout << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << data[i].ind << " ";
    }
    cout << endl;
    int ind = GetInd(data, target);
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

