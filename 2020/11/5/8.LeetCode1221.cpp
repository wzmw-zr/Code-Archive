/*************************************************************************
	> File Name: 8.LeetCode1221.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月05日 星期四 22时54分59秒
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

int balancedStringSplit(string s) {
    stack<char> st;
    int cnt = 0;
    for (int i = 0; s[i]; i++) {
        if (st.empty() || st.top() == s[i]) st.push(s[i]); 
        else {
            st.pop();
            if (st.empty()) cnt++;
        }
    }
    return cnt;
}

int main() {
    string s;
    cin >> s;
    cout << balancedStringSplit(s) << endl;
    return 0;
}
