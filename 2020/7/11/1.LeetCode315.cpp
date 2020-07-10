/*************************************************************************
	> File Name: 1.LeetCode315.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月11日 星期六 00时04分09秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    int len = nums.size();
    vector<int> cnt(len, 0);
    multiset<int> st;
    for (int i = len - 1; i >= 0; i--) {
        st.insert(nums[i]);
        cnt[i] = distance(st.begin(), st.find(nums[i]));
    }
    return cnt;
}


int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> cnt = countSmaller(nums);
    for (auto x : cnt) cout << x << " ";
    cout << endl;
    return 0;
}
