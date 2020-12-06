/*************************************************************************
	> File Name: 4.LeetCode5618.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月06日 星期日 10时35分01秒
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

int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (int x : nums) mp[x]++;
    for (int x : nums) {
        if (!mp.count(x) || !mp.count(k - x)) continue;
        if (x * 2 == k) {
            if (mp[x] >= 2) {
                ans++;
                mp[x] -= 2;
                if (mp[x] < 2) mp.erase(mp.find(x));
            } else mp.erase(mp.find(x));
        } else {
            ans++;
            if (!(--mp[x])) mp.erase(mp.find(x));
            if (!(--mp[k - x])) mp.erase(mp.find(k - x));
        }
    }
    return ans;
}

int main() {
    int k, n;
    vector<int> nums;
    cin >> k;
    while (cin >> n) nums.push_back(n);
    cout << maxOperations(nums, k) << endl;
    return 0;
}
