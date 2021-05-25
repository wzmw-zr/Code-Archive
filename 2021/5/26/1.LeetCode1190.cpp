/*************************************************************************
	> File Name: 1.LeetCode1190.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月26日 星期三 00时03分19秒
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

string reverseParentheses(string s) {
    string ans = "";
    stack<string> st;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            st.push(ans);
            ans = "";
        } else if (s[i] == ')') {
            reverse(ans.begin(), ans.end());
            if (st.empty()) continue;
            string temp = st.top();
            st.pop();
            ans = temp + ans;
        } else {
            ans += s[i];
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << reverseParentheses(s) << endl;
    return 0;
}
