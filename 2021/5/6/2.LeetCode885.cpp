/*************************************************************************
	> File Name: 2.LeetCode885.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月06日 星期四 00时08分02秒
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
void handle(int &R, int &C, int x, int y, int dis, vector<vector<int>> &ans) {
    int len = 2 * dis;
    for (int i = 0; i < len; i++) {
        int r = x + i;
        if ((r < 0 || r >= R || y < 0 || y >= C)) continue;
        ans.push_back({r, y});
    }
    for (int i = 0; i < len; i++) {
        int r = x + len - 1, c = y - 1 - i;
        if ((r < 0 || r >= R || c < 0 || c >= C)) continue;
        ans.push_back({r, c});
    }
    for (int i = 0; i < len; i++) {
        int r = x + len - 2 - i;
        int c = y - len;
        if ((r < 0 || r >= R || c < 0 || c >= C)) continue;
        ans.push_back({r, c});
    }
    for (int i = 0; i < len; i++) {
        int r = x - 1;
        int c = y - len + 1;
        if ((r < 0 || r >= R || c < 0 || c >= C)) continue;
        ans.push_back({r, c});
    }
}

vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    int mmax = max(max(r0, R - 1 - r0), max(c0, C - 1 - c0));
    vector<vector<int>> ans;
    ans.push_back({r0, c0});
    for (int i = 1; i <= mmax; i++) {
        handle(R, C, r0 - i + 1, c0 + i, i, ans);
    }
    return ans;
}

int main() {
    return 0;
}
