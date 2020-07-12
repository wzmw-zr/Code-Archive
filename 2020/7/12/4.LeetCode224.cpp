/*************************************************************************
	> File Name: 4.LeetCode224.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月12日 星期日 19时44分58秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

long get_num(string s, long &ind) {
    long res = 0;
    while (ind < s.size() && s[ind] >= '0' && s[ind] <= '9') {
        res = res * 10 + s[ind] - '0';
        ind++;
    }
    return res;
}

long calculate(string s) {
    for (long i = s.size() - 1; i >= 0; i--) {
        if (s[i] != ' ') continue;
        s.replace(i, 1, "");
    }
    cout << s << endl;
    stack<long> num;
    stack<char> symbol;
    for (long i = 0; i < s.size(); ) {
        if (s[i] == '+') {
            i++;
            if (s[i] == '(') {
                symbol.push('+');
                continue;
            }
            long number = get_num(s, i);
            long tmp = num.top();
            num.pop();
            num.push(tmp + number);
        } else if (s[i] == '-') {
            i++;
            if (s[i] == '(') {
                symbol.push('-');
                continue;
            }
            long number = get_num(s, i);
            long tmp = num.top();
            num.pop();
            num.push(tmp - number);
        } else if (s[i] == '(') {
            symbol.push(s[i++]);
        } else if (s[i] == ')') {
            symbol.pop();
            i++;
            if (symbol.size() == 0) continue;
            if (symbol.top() == '+') {
                long tmp1 = num.top();
                num.pop();
                long tmp2 = num.top();
                num.pop();
                symbol.pop();
                num.push(tmp1 + tmp2);
            } else if (symbol.top() == '-'){
                long tmp1 = num.top();
                num.pop();
                long tmp2 = num.top();
                num.pop();
                symbol.pop();
                num.push(-tmp1 + tmp2);
            }
        } else {
            long number = get_num(s, i);
            num.push(number);
        }
    }
    return num.top();
}

int main() {
    string s;
    getline(cin, s);
    cout << calculate(s) << endl;
    return 0;
}
