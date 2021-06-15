/*************************************************************************
	> File Name: 1.LeetCode877.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月16日 星期三 00时03分32秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
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

int alex_play(vector<int> &piles, int l, int r);
int li_play(vector<int> &piles, int l, int r);

int alex_play(vector<int> &piles, int l, int r) {
    if (l == r) return piles[l];
    int t1 = piles[l] - li_play(piles, l + 1, r);
    int t2 = piles[r] - li_play(piles, l, r - 1);
    return max(t1, t2);
}

int li_play(vector<int> &piles, int l, int r) {
    if (l == r) return piles[l];
    int t1 = piles[l] - alex_play(piles, l + 1, r);
    int t2 = piles[r] - alex_play(piles, l, r - 1);
    return max(t1, t2);
}

int dfs(vector<int> &piles, int l, int r) {
    if (l == r) return piles[l];
    int t1 = piles[l] - dfs(piles, l + 1, r);
    int t2 = piles[r] - dfs(piles, l, r - 1);
    return max(t1, t2);
}

bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    return alex_play(piles, 0, n - 1) > 0;
    // int dis = dfs(piles, 0, n - 1);
    // return dis > 0;
}

int main() {
    return 0;
}
