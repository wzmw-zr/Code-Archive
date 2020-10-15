/*************************************************************************
	> File Name: 2.LeetCode1803.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月15日 星期四 13时37分54秒
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

int get_num(string &s, int &ind) {
    int num = 0;
    while (s[ind] && s[ind] >= '0' && s[ind] <= '9') {
        num = num * 10 + s[ind] - '0';
        ind++;
    }
    return num;
}

int calculate(string s) {
    map<char, int> mp;
    mp['+'] = 0, mp['-'] = 0, mp['*'] = 1, mp['/'] = 1;
    stack<char> char_st;
    stack<int> num_st;
    for (int i = 0; s[i]; ) {
        while (s[i] && s[i] == ' ') i++;
        if (s[i] && s[i] >= '0' && s[i] <= '9') {
            int num = get_num(s, i);
            num_st.push(num);
        } else {
            switch (s[i++]) {
                case '+' : {
                    int num = get_num(s, i);
                    if (!char_st.empty()) {
                        char c = char_st.top();
                        if (mp[c] == mp['+']) {
                            char_st.pop();
                            int num_1 = num_st.top();
                            num_st.pop();
                            int num_2 = num_st.top();
                            num_st.pop();
                            if (c == '-') {
                                num_st.push(num_2 - num_1);
                            } else {
                                num_st.push(num_1 + num_2);
                            }
                        }
                    }
                    char_st.push('+');
                    num_st.push(num);
                } break;
                case '-' : {
                    int num = get_num(s, i);
                    if (!char_st.empty()) {
                        char c = char_st.top();
                        if (mp[c] == mp['-']) {
                            char_st.pop();
                            int num_1 = num_st.top();
                            num_st.pop();
                            int num_2 = num_st.top();
                            num_st.pop();
                            if (c == '-') {
                                num_st.push(num_2 - num_1);
                            } else {
                                num_st.push(num_1 + num_2);
                            }
                        }
                    }
                    num_st.push(num);
                    char_st.push('-');
                } break;
                case '*' : {
                    int num = get_num(s, i);
                    if (!char_st.empty()) {
                        char c = char_st.top();
                        if (mp[c] == mp['*']) {
                            char_st.pop();
                            int num_1 = num_st.top();
                            num_st.pop();
                            int num_2 = num_st.top();
                            num_st.pop();
                            if (c == '*') {
                                num_st.push(num_2 * num_1);
                            } else {
                                num_st.push(num_2 / num_1);
                            }
                        }
                    }
                    num_st.push(num);
                    char_st.push('*');
                } break;
                case '/' : {
                    int num = get_num(s, i);
                    if (!char_st.empty()) {
                        char c = char_st.top();
                        if (mp[c] == mp['/']) {
                            char_st.pop();
                            int num_1 = num_st.top();
                            num_st.pop();
                            int num_2 = num_st.top();
                            num_st.pop();
                            if (c == '*') {
                                num_st.push(num_2 * num_1);
                            } else {
                                num_st.push(num_2 / num_1);
                            }
                        }
                    }
                    num_st.push(num);
                    char_st.push('/');
                }
            }
        }
    }
    while (!char_st.empty()) {
        char c = char_st.top();
        char_st.pop();
        int num_1 = num_st.top();
        num_st.pop();
        int num_2 = num_st.top();
        num_st.pop();
        if (c == '+') {
            num_st.push(num_1 + num_2);
        } else {
            num_st.push(num_2 - num_1);
        }
    }
    return num_st.top();
}

int main() {
    return 0;
}
