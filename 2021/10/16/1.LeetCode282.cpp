/*************************************************************************
	> File Name: 1.LeetCode282.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月16日 星期六 08时22分53秒
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
#include <optional>
using namespace std;

// TLE
vector<char> ch;
unordered_map<char, int> prior;

void cal_top(stack<long> &nums, stack<char> &ops) {
    char c = ops.top();
    ops.pop();
    long x = nums.top();
    nums.pop();
    long y = nums.top();
    nums.pop();
    if (c == '+') nums.push(y + x);
    else if (c == '-') nums.push(y - x);
    else nums.push(y * x);
}

long cal_expression(string &s) {
    stack<long> nums;
    stack<char> ops;
    int ind = 0;
    while (s[ind]) {
        if (!(s[ind] >= '0' && s[ind] <= '9')) {
            if (ops.empty() || prior[s[ind]] > prior[ops.top()]) {
                ops.push(s[ind++]);
                continue;
            }
            cal_top(nums, ops);
            ops.push(s[ind++]);
        } else {
            string t = "";
            while (s[ind] && (s[ind] >= '0' && s[ind] <= '9')) t += s[ind++];
            // if (t[0] == '0' && t.size() > 1) return {};
            nums.push(stol(t));
        }
    }
    while (!ops.empty()) cal_top(nums, ops);
    return nums.top();
}

void dfs(string &num, vector<char> &ops, int ind, int &n, int &target, vector<string> &ans) {
    if (ind && ops[ind - 1] == ' ' && num[ind - 1] == '0') return ;
    if (ind == n - 1) {
        int cnt = 0;
        for (char c : ops) cnt += c == ' ' ? 0 : 1;
        string exp(n + cnt, ' ');
        int x = 0;
        for (int i = 0; i < n - 1; i++) {
            exp[x++] = num[i];
            if (ops[i] != ' ') exp[x++] = ops[i];
        }
        exp[x++] = num[n - 1];
        if (cal_expression(exp) == target) ans.push_back(exp);
        return ;
    }
    for (int i = 0; i < 4; i++) {
        ops.push_back(ch[i]);
        dfs(num, ops, ind + 1, n, target, ans);
        ops.pop_back();
    }
}

vector<string> addOperators(string num, int target) {
    ch = {' ', '+', '-', '*'};
    prior = {{'+', 0}, {'-', 0}, {'*', 1}};
    int n = num.size();
    vector<char> ops;
    vector<string> ans;
    dfs(num, ops, 0, n, target, ans);
    return ans;
}

int main() {
    string num;
    int target;
    cin >> num >> target;
    auto ans = addOperators(num, target);
    for (auto s : ans) cout << s << endl;
    return 0;
}
