/*************************************************************************
	> File Name: 1.LeetCode540.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月01日 星期二 13时45分49秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

long singleNonDuplicate(vector<long>& nums) {
    long l = 0, r = nums.size() - 1;
    while (l < r) {
        long mid = (l + r) >> 1;
        if (mid + 1 <= r) {
            if (nums[mid] == nums[mid + 1]) {
                if (mid & 1) r = mid - 1;
                else l = mid + 1;
                continue;
            }
        }
        if (mid - 1 >= 0) {
            if (nums[mid] == nums[mid - 1]) {
                if (mid & 1) l = mid + 1;
                else r = mid - 1;
                continue;
            }
        }
        return nums[mid];
    }
    return nums[l];
}

int main() {
    long n;
    vector<long> nums;
    while (cin >> n) nums.push_back(n);
    cout << singleNonDuplicate(nums) << endl;
    return 0;
}
