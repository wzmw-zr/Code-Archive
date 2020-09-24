/*************************************************************************
	> File Name: 3.LeetCode.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月19日 星期六 15时05分24秒
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
#define MAX_N 100010
#define MOD 1000000007

vector<int> numsGame(vector<int>& nums) {
    int len = nums.size();
    vector<int> ans(1, 0);
    for (int i = 0; i < nums.size(); i++) nums[i] -= i;
    for (auto &x : nums) cout << x << " ";
    cout << endl;
    for (int i = 1; i < len; i++) {
        vector<int> temp(i + 1, 0);
        for (int j = 0; j <= i; j++) temp[j] = nums[j];
        for (auto &x : temp) cout << x << " ";
        cout << endl;
        sort(temp.begin(), temp.end());
        for (auto &x : temp) cout << x << " ";
        cout << endl << endl;
        int mid = temp[temp.size() / 2];
        int num = 0;
        for (int j = 0; j <= i; j++) {
            num += abs(mid - nums[j]);
        }
        ans.push_back(num);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (auto &x : nums) cout << x << " ";
    cout << endl;
    auto ret = numsGame(nums);
    for (auto x : ret) cout << x << " ";
    cout << endl;
    return 0;
}
