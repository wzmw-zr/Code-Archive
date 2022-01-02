/*************************************************************************
	> File Name: 2.LeetCode5968.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月02日 星期日 10时40分35秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int numberOfBeams(vector<string>& bank) {
    int n = bank.size();
    vector<int> cnts(n);
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (char c : bank[i]) {
            if (c == '0') continue;
            cnt += 1;
        }
        cnts[i] = cnt;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!cnts[i]) continue;
        for (int j = i + 1; j < n; j++) {
            if (!cnts[j]) continue;
            ans += cnts[i] * cnts[j];
            break;
        }
    }
    return ans;
}

int main() {
    return 0;
}
