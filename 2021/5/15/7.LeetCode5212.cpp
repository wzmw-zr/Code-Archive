/*************************************************************************
	> File Name: 7.LeetCode5212.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月15日 星期六 23时21分13秒
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


// TLE
const int MOD = 1e9 + 7;

int sumOfFlooredPairs(vector<int>& nums) {
    map<int, int> mp;
    for (int x : nums) mp[x]++;
    int ans = 0;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        auto temp = iter;
        while (temp != mp.end()) {
            ans += ((temp->first / iter->first) * iter->second % MOD) * temp->second % MOD;
            ans %= MOD;
            temp = next(temp);
        }
    }
    return ans;
}

int main() {
    vector<int> nums;
    int n;
    while (cin >> n) nums.push_back(n);
    // for (int i = 1; i <= 1e5; i++) nums.push_back(i);
    cout << sumOfFlooredPairs(nums) << endl;
    return 0;
}
