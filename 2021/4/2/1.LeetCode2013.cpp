/*************************************************************************
	> File Name: 1.LeetCode2013.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月02日 星期五 15时14分18秒
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

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> left_max(n, -1), right_max(n, n);
    vector<int> st;
    for (int i = 0; i < n; i++) {
        while (st.size() != 0 && height[*st.rbegin()] < height[i]) st.pop_back();
        st.push_back(i);
        left_max[i] = st[0];
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (st.size() != 0 && height[*st.rbegin()] < height[i]) st.pop_back();
        st.push_back(i);
        right_max[i] = st[0];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += min(height[left_max[i]], height[right_max[i]]) - height[i];
    return ans;
}


int main() {
    return 0;
}
