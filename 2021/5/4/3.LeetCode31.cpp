/*************************************************************************
	> File Name: 3.LeetCode31.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月04日 星期二 02时50分08秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    stack<int> st;
    int n = nums.size();
    int i = n - 1;
    int pos = 0;
    for (i = n - 1; i >= 0; i--) {
        if (st.empty()) {
            st.push(i);
        } else {
            if (nums[i] >= nums[st.top()]) {
                st.push(i);   
                continue;
            }
            while (!st.empty() && nums[i] < nums[st.top()]) {
                pos = st.top();
                st.pop();
            }
            swap(nums[i], nums[pos]);
            break;
        }
    }
    sort(nums.begin() + i + 1, nums.end());
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    nextPermutation(nums);
    cout << "[";
    for (int x : nums) cout << x << ", ";
    cout << "]" << endl;
    return 0;
}
