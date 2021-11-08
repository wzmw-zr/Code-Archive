/*************************************************************************
	> File Name: 1.LeetCode299.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月08日 星期一 10时03分32秒
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

string getHint(string secret, string guess) {
    vector<int> cnt_1(10, 0), cnt_2(10, 0);
    for (char c : secret) cnt_1[c - '0']++;
    for (char c : guess) cnt_2[c - '0']++;
    int same = 0;
    for (int i = 0; secret[i]; i++) same += secret[i] == guess[i] ? 1 : 0;
    int num = 0;
    for (int i = 0; i < 10; i++) num += min(cnt_1[i], cnt_2[i]);
    string ans = to_string(same) + "A" + to_string(num - same) + "B";
    return ans;
}

int main() {
    string secret, guess;
    cin >> secret >> guess;
    cout << getHint(secret, guess) << endl;
    return 0;
}
