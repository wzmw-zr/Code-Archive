/*************************************************************************
	> File Name: 2.LeetCode1060.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月25日 星期三 19时52分44秒
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

int missingElement(vector<int>& nums, int k) {
    int n = nums.size(), ans;
    for (int i = 1; i < n; i++) {
        int temp = nums[i] - nums[i - 1] - 1;
        if (k > temp) {
            k -= temp;
        } else {
            ans = nums[i - 1] + k;
            k = 0;
            break;
        }
    }
    if (k) ans = nums[n - 1] + k;
    return ans;
}

int main() {
    int k, n;
    vector<int> nums;
    cin >> k;
    while (cin >> n) nums.push_back(n);
    cout << missingElement(nums, k) << endl;
    return 0;
}
