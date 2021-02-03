/*************************************************************************
	> File Name: 2.LeetCode480.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月03日 星期三 21时01分41秒
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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> PII;


vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    tree<PII, null_type, less<PII>, rb_tree_tag, tree_order_statistics_node_update> t;
    int left = 0, right = 0, n = nums.size();
    vector<double> ans;
    for (; right < n; right++) {
        t.insert(PII(nums[right], right));
        if (right - left + 1 < k) continue;
        double temp = (*t.find_by_order(k / 2)).first;
        temp += (*t.find_by_order((k - 1) / 2)).first;
        ans.push_back(temp / 2);
        t.erase(PII(nums[left], left));
        left++;
    }
    return ans;
}

int main() {
    return 0;
}
