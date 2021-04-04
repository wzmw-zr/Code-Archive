/*************************************************************************
	> File Name: 2.LeetCode5724.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月04日 星期日 10时43分20秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int left_nearest_ind(vector<int> &nums, int num) {
    int n = nums.size();
    int l = 0, r = n - 1;
    cout << "left_nearest_ind : " << endl;
    while (l < r) {
        cout << l << " " << r << endl;
        int mid = (l + r + 1) / 2;
        if (nums[mid] <= num) l = mid;
        else r = mid - 1;
    }
    return l;
}

int right_nearest_ind(vector<int> &nums, int num) {
    int n = nums.size();
    int l = 0, r = n - 1;
    cout << "right_nearest_ind : "  << endl;
    while (l < r) {
        cout << l << " " << r << endl;
        int mid = (l + r) / 2;
        if (nums[mid] >= num) r = mid;
        else l = mid + 1;
    }
    return l;
}

int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    const int mod = 1e9 + 7;
    map<int, vector<int>> mp;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int dis = abs(nums1[i] - nums2[i]);
        sum = (sum + dis) % mod;
        if (!mp.count(dis)) mp[dis] = vector<int>(0);
        mp[dis].push_back(i);
    }

    auto max_dis_inds = mp.rbegin()->second;
    auto max_dis = mp.rbegin()->first;

    sort(nums1.begin(), nums1.end());
    int mmin = INT32_MAX;
    for (int &x : max_dis_inds) {
        int left = left_nearest_ind(nums1, nums2[x]);
        int right = right_nearest_ind(nums1, nums2[x]);
        // if (left == -1) mmin = min(mmin, abs(nums1[0] - nums2[x]));
        //else 
        mmin = min(mmin, abs(nums1[left] - nums2[x]));
        //if (right == n) mmin = min(mmin, abs(nums1[n - 1] - nums2[x]));
        //else 
        mmin = min(mmin, abs(nums1[right] - nums2[x]));
    }

    sum = (sum - max_dis + mmin) % mod;
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums1(n);
    vector<int> nums2(n);
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];
    int ans = minAbsoluteSumDiff(nums1, nums2);
    cout << ans << endl;
    return 0;
}
