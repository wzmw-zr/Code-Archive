/*************************************************************************
	> File Name: 2.LeetCode42.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月29日 星期三 08时32分08秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

int trap(vector<int> &height) {
    stack<int> s;
    int ans = 0;
    for (int i = 0; i < height.size(); i++) {
        while (!s.empty() && height[s.top()] <= height[i]) {
            int tmp_r = s.top();
            s.pop(); 
            if (!s.empty()) {
                int mmin = min(height[s.top()], height[i]);
                int tmp_l = s.top();
                //cout << tmp_l << " " << tmp_r << endl;
                //cout << height[tmp_l] << " " << height[tmp_r] << endl << endl;
                ans += (i - tmp_l - 1) * (mmin - height[tmp_r]);
            }
        }
        s.push(i);
    }
    return ans;
}

int main() {
    int n, m;
    vector<int> height;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        height.push_back(m);
    }
    cout << trap(height) << endl;
    return 0;
}
