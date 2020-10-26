/*************************************************************************
	> File Name: 1.LeetCode1365.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月26日 星期一 07时42分10秒
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

int b_s(int target, vector<int> &sorted) {
    int len = sorted.size();
    int l = 0, r = len - 1, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (target <= sorted[mid]) r = mid;
        else l = mid + 1;
    }
    return l;
}

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> ans, sorted = nums;
    sort(sorted.begin(), sorted.end());
    for (int &x : nums) ans.push_back(b_s(x, sorted));
    return ans;
}
 
int main() {
    int x;
    vector<int> nums;
    while (cin >> x) nums.push_back(x);
    vector<int> ans = smallerNumbersThanCurrent(nums);
    for (int &x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
