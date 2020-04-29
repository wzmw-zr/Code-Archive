/*************************************************************************
	> File Name: 3.LeetCode84.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 10时35分14秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
    int len = heights.size();
    int left[len + 5], right[len + 5];
    stack<int> s_l, s_r;
    for (int i = 0; i < len; i++) {
        while (!s_l.empty() && heights[s_l.top()] >= heights[i]) s_l.pop();
        if (!s_l.empty()) left[i] = s_l.top();
        else left[i] = -1;
        s_l.push(i);
    }
    for (int i = len - 1; i >= 0; i--) {
        while (!s_r.empty() && heights[s_r.top()] >= heights[i]) {
            s_r.pop();
        }
        if (!s_r.empty()) right[i] = s_r.top();
        else right[i] = len;
        s_r.push(i); 
    }
    int mmax = 0;
    for (int i = 0; i < len; i++) {
        mmax = max(mmax, heights[i] * (right[i] - left[i] - 1)); 
    }
    return mmax;
}

int main() {
    int n, tmp;
    vector<int> heights;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        heights.push_back(tmp);
    }
    cout << largestRectangleArea(heights) << endl;
    return 0;
}
