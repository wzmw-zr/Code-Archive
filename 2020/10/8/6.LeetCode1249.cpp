/*************************************************************************
	> File Name: 6.LeetCode1249.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月08日 星期四 19时42分39秒
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

string minRemoveToMakeValid(string s) {
    stack<int> st;
    set<int> invalid;
    string ans = "";
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')') {
            if (st.empty()) invalid.insert(i);
            else if (s[st.top()] == '(') st.pop();
            else invalid.insert(i);
        }
    }
    while (!st.empty()) {
        invalid.insert(st.top());
        st.pop();
    }
    for (int i = 0; s[i]; i++) {
        if (invalid.find(i) == invalid.end()) ans += s[i];
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << minRemoveToMakeValid(s) << endl;
    return 0;
}
