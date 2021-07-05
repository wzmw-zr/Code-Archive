/*************************************************************************
	> File Name: 1.LeetCode772.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月05日 星期一 19时15分49秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    Solution() = default;

    int parse_num(string &s, int &ind) {
        int num = 0;
        while (s[ind] && (s[ind] >= '0' && s[ind] <= '9')) {
            num = num * 10 + (s[ind] - '0');
            ind++;
        }
        return num;
    }

    int calculate(string s) {
        int ind = 0;
        unordered_map<char, int> priority;
        priority['+'] = priority['-'] = 0;
        priority['*'] = priority['/'] = 1;
        stack<int> nums;
        stack<char> ops;
        if (s[0] == '+' || s[0] == '-') nums.push(0);
        while (s[ind]) {
            if (s[ind] == ' ') ind++;
            else if (s[ind] >= '0' && s[ind] <= '9') nums.push(parse_num(s, ind));
            else if (priority.count(s[ind])) {
                while (!ops.empty() && (priority[s[ind]] <= priority[ops.top()])) {
                    int right = nums.top();
                    nums.pop();
                    int left = nums.top();
                    nums.pop();
                    char op = ops.top();
                    ops.pop();
                    switch (op) {
                        case '+' : nums.push(left + right); break;
                        case '-' : nums.push(left - right); break;
                        case '*' : nums.push(left * right); break;
                        case '/' : nums.push(left / right); break;
                    }
                }
                ops.push(s[ind++]);
            } else if (s[ind] == '(') {
                int left = ++ind;
                int cnt = 1;
                while (cnt) {
                    if (s[ind] == '(') cnt++;
                    else if (s[ind] == ')') cnt--;
                    ind++;
                }
                int right = ind - 2;
                nums.push(calculate(s.substr(left, right - left + 1)));
            }
        }
        while (!ops.empty()) {
            int right = nums.top();
            nums.pop();
            int left = nums.top();
            nums.pop();
            char op = ops.top();
            ops.pop();
            switch (op) {
                case '+' : nums.push(left + right); break;
                case '-' : nums.push(left - right); break;
                case '*' : nums.push(left * right); break;
                case '/' : nums.push(left / right); break;
            }
        }
        return nums.top();
    }
};


int main() {
    Solution solution = Solution();
    string s;
    getline(cin, s);
    cout << s << endl;
    cout << solution.calculate(s) << endl;
    return 0;
}
