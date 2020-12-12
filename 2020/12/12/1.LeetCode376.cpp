/*************************************************************************
	> File Name: 1.LeetCode376.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月12日 星期六 08时12分17秒
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

int wiggleMaxLength(vector<int>& nums) {
    vector<int> dif;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) dif.push_back(nums[i + 1] - nums[i]);
    for (int &x : dif) cout << x << " ";
    cout << endl;
    vector<int> len(n - 1, 1);
    int ans = 1;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < i; j++) {
            if ((dif[i] > 0 && dif[j] < 0) || (dif[i] < 0 && dif[j] > 0)) len[i] = max(len[i], len[j] + 1);
        }
        ans = max(ans, len[i]);
    }
    return ans + 1;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << wiggleMaxLength(nums) << endl;
    return 0;
}
