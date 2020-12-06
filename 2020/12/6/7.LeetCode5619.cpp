/*************************************************************************
	> File Name: 7.LeetCode5619.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月06日 星期日 11时10分51秒
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

int minimumIncompatibility(vector<int>& nums, int k) {
    int n = nums.size();
    int m = n / k;
    map<int, int> mp;
    int ans = 0;
    for (int x : nums) mp[x]++;
    for (auto x : mp) {
        if (x.second > k) return -1;
    }
    while (m--) {
        int cnt = m;
        int first, end, flag = 0;
        for (auto x : mp) {
            if (x.second) {
                if (!flag) {
                    first = end = x.first;
                    flag = 1;
                } else {
                    end = x.first;
                }
                x.second--;
                cnt--;
            }
            if (cnt) continue;
            break;
        }
        ans += end - first;
    } 
    return ans;
}

int main() {
    int k, n;
    vector<int> nums;
    cin >> k;
    while (cin >> n) nums.push_back(n);
    cout << minimumIncompatibility(nums, k) << endl;
    return 0;
}
