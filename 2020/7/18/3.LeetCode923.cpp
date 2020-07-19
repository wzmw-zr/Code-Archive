/*************************************************************************
	> File Name: 3.LeetCode923.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月18日 星期六 16时27分24秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

long threeSumMulti(vector<long>& A, long target) {
    unordered_map<long, long> mp;
    vector<long> nums;
    for (auto &x : A) mp[x]++;
    for (auto &x : mp) nums.push_back(x.first);
    sort(nums.begin(), nums.end());
    long len = nums.size();
    long cnt = 0;
    long MOD = 1000000007;
    for (long i = 0; i < len - 2; i++) {
        long l = i + 1, r = len - 1;
        while (l < r) {
            long sum = nums[i] + nums[l] + nums[r];
            if (sum == target) {
                cnt += mp[nums[i]] * mp[nums[l]] * mp[nums[r]];
                cnt %= MOD;
                l++, r--;
            } else if (sum < target) l++;
            else r--;
        }
    }
    for (long i = 0; i < len - 1; i++) {
        if (mp[nums[i]] < 2) continue;
        long ind = len - 1;
        while (ind > i) {
            long sum = 2 * nums[i] + nums[ind];
            if (sum == target) {
                cnt += mp[nums[i]] * (mp[nums[i]] - 1) * mp[nums[ind]] / 2;
                cnt %= MOD;
                break;
            } else if (sum > target) ind--;
            else break;
        }
    }
    for (long i = 0; i < len - 1; i++) {
        long ind = len - 1;
        while (ind > i) {
            if (mp[nums[ind]] >= 2) {
                long sum = nums[i] + 2 * nums[ind];
                if (sum == target) {
                    cnt += mp[nums[i]] * mp[nums[ind]] * (mp[nums[ind]] - 1) / 2;
                    cnt %= MOD;
                    break;
                }
                else if (sum < target) break;
            }
            ind--;
        }
    }
    for (long i = 0; i < len; i++) {
        if (mp[nums[i]] < 3) continue;
        if (3 * nums[i] == target) {
            cnt += mp[nums[i]] * (mp[nums[i]] - 1) * (mp[nums[i]] - 2) / 6;
            cnt %= MOD;
            break;
        } else if (3 * nums[i] < target) i++;
        else break;
    }
    return cnt;
}

int main() {
    return 0;
}
