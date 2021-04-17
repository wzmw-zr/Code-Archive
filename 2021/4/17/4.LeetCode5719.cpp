/*************************************************************************
	> File Name: 4.LeetCode5719.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月17日 星期六 22时40分01秒
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

int getMaximumXor(int xor_num, int maximumBit) {
    int len = 0;
    for (int i = 0; i <= 31; i++) {
        if (xor_num & (1 << i)) len = i;
    }
    cout << "num = " << xor_num << " len = " << len << endl;
    len = (len <= maximumBit - 1) ? maximumBit - 1 : len;
    int ans = 0;
    for (int i = 0; i <= len; i++) {
        if (xor_num & (1 << i)) continue;
        ans |= (1 << i);
    }
    return ans;
}

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    vector<int> ans;
    int xor_num = 0, n = nums.size();
    for (int i = 0; i < n; i++) xor_num ^= nums[i];
    for (int i = n - 1; i >= 0; i--) {
        int temp = getMaximumXor(xor_num, maximumBit);
        cout << xor_num << " " << temp << endl;
        ans.push_back(temp);
        xor_num ^= nums[i];
    }
    return ans;
}

int main() {
    int maximumBit, n;
    cin >> maximumBit;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    auto ans = getMaximumXor(nums, maximumBit);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
