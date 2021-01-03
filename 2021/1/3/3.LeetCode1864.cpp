/*************************************************************************
	> File Name: 3.LeetCode1864.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月03日 星期日 09时01分43秒
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

unordered_map<string, int> one_map;
unordered_map<string, int> zero_map;

int countEval(string s, int result) {
    if (result > 1 || result < 0) return 0;
    if (s.size() == 1) return (s[0] - '0' == result) ? 1 : 0;
    int n = s.size(), cnt = 0;
    for (int i = 0; (i + 2) < n; i += 2) {
        int one_left = 0, zero_left = 0, one_right = 0, zero_right = 0;
        string left = s.substr(0, i + 1);
        string right = s.substr(i + 2);
        if (one_map.count(left)) {
            one_left = one_map[left];
            zero_left = zero_map[left];
        } else {
            one_left = countEval(left, 1);
            zero_left = countEval(left, 0);
            one_map[left] = one_left;
            zero_map[left] = zero_left;
        }
        if (one_map.count(right)) {
            one_right = one_map[right];
            zero_right = zero_map[right];
        } else {
            one_right = countEval(right, 1);
            zero_right = countEval(right, 0);
            one_map[right] = one_right;
            zero_map[right] = zero_right;
        }
        if (result) {
            if (s[i + 1] == '|') cnt += one_left * one_right + one_left * zero_right + zero_left * one_right;
            else if (s[i + 1] == '&') cnt += one_left * one_right;
            else cnt += one_left * zero_right + zero_left * one_right;
        } else {
            if (s[i + 1] == '|') cnt += zero_left * zero_right;
            else if (s[i + 1] == '&') cnt += one_left * zero_right + zero_left * one_right + zero_left * zero_right;
            else cnt += one_left * one_right + zero_left * zero_right;
        }
    }
    return cnt;
}

int main() {
    string s;
    int result;
    cin >> s >> result;
    cout << countEval(s, result) << endl;
    return 0;
}
