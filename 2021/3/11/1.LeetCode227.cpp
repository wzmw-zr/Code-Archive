/*************************************************************************
	> File Name: 1.LeetCode227.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月11日 星期四 07时38分18秒
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

long get_num(string &s, int &ind) {
    long num = 0;
    while (s[ind] && s[ind] >= '0' && s[ind] <= '9') {
        num = num * 10 + s[ind] - '0';
        ind++;
    }
    return num;
}

int calculate(string s) {
    stack<long> nums;
    stack<char> ops;
    for (int i = 0; s[i]; ) {
        if (s[i] == ' ') {
            i++;
        } else if (s[i] == '+' || s[i] == '-') {
            while (!ops.empty() && (ops.top() == '+' || ops.top() == '-')) {
                long x = nums.top();
                nums.pop();
                long y = nums.top();
                nums.pop();
                char c = ops.top();
                ops.pop();
                if (c == '+') nums.push(y + x);
                else nums.push(y - x);
            }
            ops.push(s[i++]);
        } else if (s[i] == '*' || s[i] == '/') {
            char c = s[i++];
            while (s[i] && s[i] == ' ') i++;
            long num = get_num(s, i);
            long x = nums.top();
            nums.pop();
            if (c == '*') nums.push(x * num);
            else nums.push(x / num);
        } else {
            long num = get_num(s, i);
            nums.push(num);
        }
    }
    if (ops.empty()) return nums.top();
    long x = nums.top();
    nums.pop();
    long y = nums.top();;
    nums.pop();
    if (ops.top() == '+') return y + x;
    return y - x;
}

int main() {
    return 0;
}
