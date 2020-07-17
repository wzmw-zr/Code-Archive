/*************************************************************************
	> File Name: 2.LeetCode15.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月17日 星期五 22时58分02秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

int find(int goal, int ind, vector<int> &nums) {
    int l = ind, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (nums[mid] + goal == 0) return mid;
        else if (nums[mid] + goal < 0)  l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) return res;
    set<vector<int>> st;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            int tmp = nums[i] + nums[j];
            int ret = find(tmp, j + 1, nums);
            if (ret == -1) continue;
            vector<int> item(3, 0);
            item[0] = nums[i], item[1] = nums[j], item[2] = nums[ret];
            st.insert(item);
        }
    }
    for (auto &x : st) res.push_back(x);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<int>> res = threeSum(nums);
    for (vector<int> &x : res) {
        for (int y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}
