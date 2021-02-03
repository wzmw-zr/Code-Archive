/*************************************************************************
	> File Name: 1.LeetCode480.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月03日 星期三 17时49分57秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iterator>
using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    multiset<int> st;
    vector<double> ans;
    for (int i = 0; i < k - 1; i++) st.insert(nums[i]);
    for (int i = k - 1; i < n; i++) {
        if (st.size() == k) st.erase(st.find(nums[i - k]));
        st.insert(nums[i]);
        auto iter = st.begin();
        advance(iter, k / 2);
        if (k & 1) ans.push_back(*iter);
        else {
            double temp = *iter--;
            temp += *iter;
            temp /= 2;
            ans.push_back(temp);
        }
    }
    return ans;
}

int main() {
    return 0;
}
