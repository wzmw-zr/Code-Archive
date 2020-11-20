/*************************************************************************
	> File Name: 2.LeetCode1414.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月20日 星期五 08时10分33秒
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

int findMinFibonacciNumbers(int k) {
    unordered_map<long, int> mp;
    vector<long> nums({1, 1});
    mp[1] = 1, mp[2] = 2;
    int ind = 2;
    while (nums[ind - 2] + nums[ind - 1] <= (long) k) {
        long temp = nums[ind - 2] + nums[ind - 1];
        unordered_map<long, int> mp_t;
        for (auto &x : mp) {
            if (!mp.count(temp + x.first)) mp_t[temp + x.first] = x.second + 1;
            else mp_t[temp + x.first] = min(x.second + 1, mp[temp + x.first]);
        }
        for (auto &x : mp_t) mp[x.first] = x.second;
        mp[temp] = 1;
        nums.push_back(temp);
        ind++;
    }
    return mp[k];
}

int main() {
    int k;
    cin >> k;
    cout << findMinFibonacciNumbers(k) << endl;
    return 0;
}
