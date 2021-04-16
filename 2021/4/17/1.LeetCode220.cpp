/*************************************************************************
	> File Name: 1.LeetCode220.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月17日 星期六 00时12分01秒
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


bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();
    set<long> st;
    for (int i = 0; i < n; i++) {
        auto iter = st.lower_bound(max(nums[i], INT32_MIN + t) - t);
        if (iter != st.end() && *iter <= min(nums[i], INT32_MAX - t) + t) return true;
        st.insert(nums[i]);
        if (i >= k) st.erase(nums[i - k]);
    }
    return false;
}

# if 0
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();
    for (int i = 0; i < n - k; i++) {
        for (int l = 1; l <= k; l++) {
            if (abs(nums[i] - nums[i + l]) <= t) return true;
        }
    }
    return false;
}
# endif 

int main() {
    int k, t, num;
    vector<int> nums;
    cin >> k >> t;
    while (cin >> num) nums.push_back(num);
    cout << (containsNearbyAlmostDuplicate(nums, k, t) ? "True" : "False") << endl;
    return 0;
}
