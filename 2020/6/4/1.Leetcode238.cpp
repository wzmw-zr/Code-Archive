/*************************************************************************
	> File Name: 1.Leetcode238.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月04日 星期四 07时12分18秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> left(nums.size(), 1);
    vector<int> right(nums.size(), 1);
    vector<int> ret(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
        left[i] = left[i - 1] * nums[i - 1];
    }
    for (int i = nums.size() - 2; i >= 0; i--) {
        right[i] = right[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < nums.size(); i++) {
        ret[i] = left[i] * right[i];
    }
    return ret;
}
 
int main() {
    int n;
    cin >> n;
    vector<int> nums, ret;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    ret = productExceptSelf(nums); 
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}
