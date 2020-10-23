/*************************************************************************
	> File Name: 2.LeetCode255.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月23日 星期五 09时17分37秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

bool verifyPreorder(vector<int>& preorder) {
    stack<int> st;
    int mmin = INT32_MIN;
    for (int i = 0; i < preorder.size(); i++) {
        if (preorder[i] < mmin) return false;
        while (!st.empty() && preorder[i] > st.top()) {
            mmin = st.top();
            st.pop();
        }
        st.push(preorder[i]);
    }
    return true;
}

int main() {
    return 0;
}
