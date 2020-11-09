/*************************************************************************
	> File Name: 1.LeetCode31.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月10日 星期二 00时02分55秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    int i, j;
    for (i = n - 1; i >= 0; i--) {
        vector<int> temp = nums;
        for (j = i - 1; j >= 0; j--) {
            if (nums[i] <= nums[j]) continue;
            swap(temp[i], temp[j]);
            sort(temp.begin() + (j + 1), temp.end());
            ans.push_back(temp);
            break;
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.size()) nums = ans[0]; 
    else reverse(nums.begin(), nums.end());
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    nextPermutation(nums);
    cout << "===================================" << endl;
    for (int x : nums) cout << x << " ";
    cout << endl;
    return 0;
}
