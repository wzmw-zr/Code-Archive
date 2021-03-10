/*************************************************************************
	> File Name: 1.LeetCode224.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月10日 星期三 07时53分59秒
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


// WA

int get_num(string &s, int &ind) {
    string num = "";
    while (s[ind] && s[ind] >= '0' && s[ind] <= '9') num += s[ind++];
    return stoi(num);
}

int calculate(string s) {
    stack<int> nums;
    stack<char> ops;
    for (int i = 0; s[i]; ) {
        if (s[i] == ' ') {
            i++;
            continue;
        }
        if (s[i] == '+' || s[i] == '-' || s[i] == '(') {
            ops.push(s[i++]);
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            int num = get_num(s, i);
            nums.push(num);
            continue;
        }
        if (s[i] == ')') {
            while (ops.top() != '(') {
                int x = nums.top();
                nums.pop();
                int y = nums.top();
                nums.pop();
                if (ops.top() == '+') nums.push(y + x);
                else nums.push(y - x);
                ops.pop();
            }
            ops.pop();
            i++;
        }
    }
    while (!ops.empty()) {
        int x = nums.top();
        nums.pop();
        int y = nums.top();
        nums.pop();
        if (ops.top() == '+') nums.push(y + x);
        else nums.push(y - x);
        ops.pop();
    }
    return nums.top();
}

int main() {
    return 0;
}
