/*************************************************************************
	> File Name: 3.LeetCode150.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月15日 星期三 15时47分42秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int to_num(string s) {
    int flag = 1, num = 0;
    if (s[0] == '-') {
        s.replace(0, 1, "");
        flag = -1;
    }
    for (int i = 0; i < s.size(); i++) {
        num = num * 10 + s[i] - '0';
    }
    return num * flag;
}

int evalRPN(vector<string>& tokens) {
    int t_len = tokens.size();
    stack<int> st;

    for (int i = 0; i < t_len; i++) {
        if (tokens[i] == "+") {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(y + x);
        } else if (tokens[i] == "-") {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(y - x);
        } else if (tokens[i] == "*") {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(y * x);
        } else if (tokens[i] == "/") {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            st.push(y / x);
        } else {
            int num = to_num(tokens[i]);
            st.push(num);
        }
    }

    return st.top();
}

int main() {
    return 0;
}
