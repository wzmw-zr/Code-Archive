/*************************************************************************
	> File Name: 3.LeetCode474.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月12日 星期五 22时31分22秒
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

// Misunderstand the meaning of the description of problem.

void get_cnt(string &s, vector<int> &cnts) {
    for (char &c : s) cnts[c - '0']++;
}

int findMaxForm(vector<string>& strs, int m, int n) {
    int ans = 0;
    for (string &s : strs) {
        vector<int> cnts(2, 0);
        get_cnt(s, cnts);
        if (cnts[0] > m || cnts[1] > n) continue;
        if (cnts[0] == m && cnts[1] == n) continue;
        ans++;
    }
    return ans;
}

int main() {
    return 0;
}
