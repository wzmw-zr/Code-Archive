/*************************************************************************
	> File Name: 4.LeetCode5691.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月28日 星期日 11时06分14秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    if (len1 > 6 * len2 || len2 > 6 * len1) return -1;
    int sum1 = 0, sum2 = 0;
    for (int &x : nums1) sum1 += x;
    for (int &x : nums2) sum2 += x;
    if (sum1 == sum2) return 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int cnt = 0;
    if (sum1 > sum2) {
        int ind1 = len1 - 1, ind2 = 0;
        while (sum1 > sum2) { 
            if (ind2 == len2 || nums1[ind1] - 1 > 6 - nums2[ind2]) sum1 -= nums1[ind1--] - 1;
            else sum2 += 6 - nums2[ind2++];
            cnt++;
        }
        return cnt;
    }
    int ind1 = 0, ind2 = len2 - 1;
    while (sum1 < sum2) {
        if (ind1 == len1 || nums2[ind2] - 1 > 6 - nums1[ind1]) sum2 -= nums2[ind2--] - 1;
        else sum1 += 6 - nums1[ind1++];
        cnt++;
    }
    return cnt;
}

int main() {
    return 0;
}
