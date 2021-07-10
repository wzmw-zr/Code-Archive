/*************************************************************************
	> File Name: 3.LeetCode5794.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月10日 星期六 22时53分45秒
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

// WA, this solution use greedy algorithm, but this problem should use DP.
bool sumGame(string num) {
    int left = 0, right = 0;
    int n = num.size();
    int dis = 0;
    for (int i = 0; i < n; i++) {
        if (num[i] == '?') {
            if ((i + 1) * 2 <= n) left++;
            else right++;
        }
        if ((i + 1) * 2 <= n) dis += (num[i] - '0');
        else dis -= (num[i] - '0');
    }
    int flag = 0;
    while (left || right) {
        if (flag) {
            if (dis > 0) {
                if (right) dis = dis <= 9 ? 0 : dis - 9, right--;
                else left--;
            } else if (dis == 0) {
                if (left >= right) left--;
                else right--;
            } else {
                if (left) dis = dis >= -9 ? 0 : dis + 9, left--;
                else right--;
            }
        } else {
            if (dis > 0) {
                if (left) dis += 9, left--;
                else right--;
            } else if (dis == 0) {
                if (right >= left) right--;
                else left--;
            } else {
                if (right) dis -= 9, right--;
                else left--;
            }
        }
        flag = !flag;
    }
    return dis != 0;
}

int main() {
    string num;
    cin >> num;
    cout << (sumGame(num) ? "True" : "False") << endl;
    return 0;
}
