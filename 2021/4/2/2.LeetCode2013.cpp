/*************************************************************************
	> File Name: 2.LeetCode2013.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月02日 星期五 16时16分42秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[st.top()] < height[i]) {
            int top = st.top();
            st.pop();
            if (st.empty()) break;
            int left = st.top();
            int currWidth = i - left - 1;
            int currHeight = min(height[left], height[i]) - height[top];
            ans += currWidth * currHeight;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    return 0;
}
