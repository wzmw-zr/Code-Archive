/*************************************************************************
	> File Name: 4.LeetCode5955.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月12日 星期日 22时17分40秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

const int MAX_N = 4 * 1e5 + 10;

int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
    int offset = max(0, k - startPos + 1);
    for (auto fruit : fruits) {
        if (fruit[0]) continue;
        offset = max(offset, 1);
        break;
    }
    long pre[MAX_N + offset];
    memset(pre, 0, sizeof(pre));
    for (auto fruit : fruits) pre[fruit[0] + offset] = fruit[1];
    for (int i = 1; i < MAX_N + offset; i++) pre[i] += pre[i - 1];
    long ans = 0;
    for (int i = 0; i <= k / 2; i++) {
        ans = max(ans, pre[startPos + offset + k - 2 * i] - pre[startPos + offset - i - 1]);
        ans = max(ans, pre[startPos + offset + i] - pre[startPos + offset - (k - 2 * i) - 1]);
    }
    return ans;
}

int main() {
    return 0;
}
