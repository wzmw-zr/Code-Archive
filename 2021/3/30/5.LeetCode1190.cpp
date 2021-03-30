/*************************************************************************
	> File Name: 5.LeetCode1190.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月30日 星期二 20时41分35秒
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
    stack<string> st;
    string str = "";
    int ind = 0;
    while (s[ind]) {
        if (s[ind] == '(') {
            if (str.size() != 0) st.push(str);
            str = "";
            st.push("(");
        } else if (s[ind] == ')') {
            string temp = "";
            while (st.top() != "(") {
                temp = st.top() + temp;
                st.pop();
            }
            if (str.size() != 0) temp = temp + str;
            str = "";
            st.pop();
            reverse(temp.begin(), temp.end());
            st.push(temp);
        } else str += s[ind];
        ind++;
    }
    if (str.size() != 0) st.push(str);
    str = "";
    string ans = "";
    while (!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << reverseParentheses(s) << endl;
    return 0;
}
