/*************************************************************************
	> File Name: 12.LeetCode772.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月15日 星期三 23时16分03秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

int get_num(string s, int &ind) {
    int ret = 0;
    while (ind < s.size() && s[ind] >= '0' && s[ind] <= '9') {
        ret = ret * 10 + s[ind] - '0';
        ind++;
    }
    return ret;
}

int calculate(string s) {
    stack<char> c_st;
    vector<int> ans;
    unordered_map<char, int> mp;
    mp['-'] = 1, mp['+'] = 1, mp['*'] = 2, mp['/'] = 2;

    for (int i = 0; i < s.size(); ) {
        switch(s[i]) {
            case '(': {
                c_st.push(s[i++]);
            } break;

            case ')': {
                while (c_st.top() != '(') {
                    ans.push_back(c_st.top());
                    c_st.pop();
                }
                c_st.pop();
                i++;
            } break;

            case '-': {
                int flag = (i == 0 || s[i - 1]) ? 1 : 0;
                if (flag) {
                    i++;
                    int num = get_num(s, i);
                    ans.push_back(num * -1);
                    break;
                }
            }
            case '+': {
                int flag = (i == 0 || s[i - 1]) ? 1 : 0;
                if (flag) {
                    i++;
                    int num = get_num(s, i);
                    ans.push_back(num);
                    break;
                }
            }
            case '*':
            case '/': {
                while (!c_st.empty() && mp[c_st.top()] >= mp[s[i]]) {
                    ans.push_back(c_st.top());
                    c_st.pop();
                }
                c_st.push(s[i++]);
            } break;

            default: {
                int num = get_num(s, i);
                ans.push_back(num);
            }
            break;
        }
    }
    return 0;
}

int main() {
    return 0;
}
