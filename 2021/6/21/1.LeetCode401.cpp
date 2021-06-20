/*************************************************************************
	> File Name: 1.LeetCode401.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月21日 星期一 00时05分30秒
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

void dfs(int ind, int num, int turnedOn, vector<string> &ans) {
    if (turnedOn == 0) {
        int hour = num & (0b1111);
        int minute = (num >> 4) & (0b111111);
        cout << hour << " " << minute << endl;
        if ((hour >= 0) && (hour <= 11) && (minute >= 0) && (minute <= 59)) {
            string temp = to_string(hour) + ":";
            if (minute >= 10) temp += to_string(minute);
            else temp += "0" + to_string(minute);
            ans.push_back(temp);
        }
        return ;
    }
    if (ind == 10) return ;
    dfs(ind + 1, num, turnedOn, ans);
    dfs(ind + 1, num | (1 << ind), turnedOn - 1, ans);
}

vector<string> readBinaryWatch(int turnedOn) {
    vector<string> ans;
    dfs(0, 0, turnedOn, ans);
    sort(ans.begin(), ans.end());
    return ans;
}


int main() {
    int turnedOn;
    cin >> turnedOn;
    auto ans = readBinaryWatch(turnedOn);
    for (auto &x : ans) cout << x << endl;
    return 0;
}
