/*************************************************************************
	> File Name: 1.LeetCode150.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月20日 星期六 00时03分35秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<long> st;
    for (string &s : tokens) {
        if (s.size() > 1 || (s[0] >= '0' && s[0] <= '9')) st.push(stoi(s));
        else {
            long s1 = st.top();
            st.pop();
            long s2 = st.top();
            st.pop();
            if (s[0] == '+') st.push(s2 + s1);
            else if (s[0] == '-') st.push(s2 - s1);
            else if (s[0] == '*') st.push(s2 * s1);
            else st.push(s2 / s1);
        }
    }
    return st.top();
}

int main() {
    return 0;
}
