/*************************************************************************
	> File Name: 11.LeetCode772.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月15日 星期三 22时02分01秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

long get_num(string s, long &ind) {
    long ret = 0;
    while (ind < s.size() && s[ind] >= '0' && s[ind] <= '9') {
        ret = ret * 10 + s[ind] - '0';
        ind++;
    }
    return ret;
}

long calculate(string s) {
    unordered_map<char, long> mp;
    mp['+'] = 1, mp['-'] = 1, mp['*'] = 2, mp['/'] = 2;
    stack<char> c_st;
    stack<long> n_st;

    for (long i = 0; i < s.size(); ) {
        switch (s[i]) {
            case ' ': {
                i++;
                break;
            }
            case '-': {
                if (i == 0 || s[i - 1] == '(') n_st.push(0);
            }
            case '+':
            case '*':
            case '/': {
                while (!c_st.empty() && c_st.top() != '(' && mp[c_st.top()] >= mp[s[i]]) {
                    char tmp = c_st.top();
                    c_st.pop();
                    long y = n_st.top();
                    n_st.pop();
                    long x = n_st.top();
                    n_st.pop();
                    switch (tmp) {
                        case '+': n_st.push(x + y); break;
                        case '-': n_st.push(x - y); break;
                        case '*': n_st.push(x * y); break;
                        case '/': n_st.push(x / y); break;
                    }
                }
                c_st.push(s[i]);
                i++;
            } break;

            case '(': {
                c_st.push(s[i]); 
                i++;
            } break;

            case ')': {
                while (c_st.top() != '(') {
                    long y = n_st.top();
                    n_st.pop();
                    long x = n_st.top();
                    n_st.pop();
                    switch(c_st.top()) {
                        case '+': n_st.push(x + y); break;
                        case '-': n_st.push(x - y); break;
                        case '*': n_st.push(x * y); break;
                        case '/': n_st.push(x / y); break;
                    }
                    c_st.pop();
                }
                c_st.pop();
                i++;
            } break;

            default: {
                long num = get_num(s, i);
                n_st.push(num);
            }
        }
    }
    while (!c_st.empty()) {
        long y = n_st.top();
        n_st.pop();
        long x = n_st.top();
        n_st.pop();
        switch(c_st.top()) {
            case '+': n_st.push(x + y); break;
            case '-': n_st.push(x - y); break;
            case '*': n_st.push(x * y); break;
            case '/': n_st.push(x / y); break;
        }
        c_st.pop();
    }
    return n_st.top();
}

int main() {
    string s;
    getline(cin, s);
    cout << calculate(s) << endl;
    return 0;
}
