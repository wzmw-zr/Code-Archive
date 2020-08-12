/*************************************************************************
	> File Name: 2.Nowcode.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月12日 星期三 19时17分42秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ']') {
            char t[100005] = {0};
            int cnt = 0;
            while (st.top() != '|') {
                t[cnt++] = st.top();
                st.pop();
            }
            st.pop();
            int times = 0, ind = 1;
            while (st.top() != '[') {
                times += (st.top() - '0') * ind;
                ind *= 10;
                st.pop();
            }
            st.pop();
            for (int j = 0; j < times; j++) {
                for (int k = cnt - 1; k >= 0; k--) {
                    st.push(t[k]);
                }
            }
        } else {
            st.push(s[i]);
        }
    }
    char ans[100005] = {0};
    int cnt = 0;
    while (!st.empty()) {
        ans[cnt++] = st.top();
        st.pop();
    }
    for (int i = cnt - 1; i >= 0; i--) cout << ans[i];
    cout << endl;
    return 0;
}
