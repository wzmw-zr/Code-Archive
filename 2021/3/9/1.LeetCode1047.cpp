/*************************************************************************
	> File Name: 1.LeetCode1047.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月09日 星期二 07时43分05秒
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

string removeDuplicates(string S) {
    stack<char> st;
    for (int i = 0; S[i]; i++) {
        if (st.empty()) st.push(S[i]);
        else {
            if (st.top() == S[i]) st.pop();
            else st.push(S[i]);
        }
    }
    int n = st.size();
    string ans(n, ' ');
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}

int main() {
    return 0;
}
