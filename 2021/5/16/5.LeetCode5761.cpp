/*************************************************************************
	> File Name: 5.LeetCode5761.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月16日 星期日 10时49分32秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int x : nums2) mp[x]++;
    }

    void add(int index, int val) {
        if (!(--mp[this->nums2[index]])) mp.erase(mp.find(this->nums2[index]));
        this->nums2[index] += val;
        mp[this->nums2[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (int x : nums1) {
            int res = tot - x;
            if (!this->mp.count(res)) continue;
            ans += mp[res];
        }
        return ans;
    }
};

int main() {
    return 0;
}
