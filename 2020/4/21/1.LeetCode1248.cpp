/*************************************************************************
	> File Name: 1.LeetCode1248.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月21日 星期二 09时59分55秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int numberOfSubarrays(vector<int> &nums, int k) {
    int len = nums.size();
    int left = 0, right = 0;
    int cnt = 0, total=0;
    while (right < len) {
        if (nums[right] % 2) {
            cnt++;
        }
        if (cnt > k) {
            while (nums[left] % 2 == 0) left++;
            left++;
            cnt--;
        }
        if (cnt == k) {
            int temp_l = left;
            while (nums[temp_l] % 2 == 0) {
                total++;
                temp_l++;
            }
            total++;
            cout << "left = " << left << " right = " << right << endl;
        }
        right++;
    }
    return total;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    int res = numberOfSubarrays(nums, k);
    cout << res << endl;
    return 0;
}
