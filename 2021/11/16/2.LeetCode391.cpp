/*************************************************************************
	> File Name: 2.LeetCode391.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月16日 星期二 15时29分48秒
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

using PII = pair<int, int>;

bool isRectangleCover(vector<vector<int>> &rectangles) {
    map<PII, int> mp;
    for (auto rec : rectangles) {
        mp[PII(rec[0], rec[1])]++;
        mp[PII(rec[0], rec[3])]++;
        mp[PII(rec[2], rec[1])]++;
        mp[PII(rec[2], rec[3])]++;
    }
    int sum = 0;
    int xmin = INT32_MAX, ymin = INT32_MAX, xmax = INT32_MIN, ymax = INT32_MIN;
    for (auto rec : rectangles) {
        sum += (rec[2] - rec[0]) * (rec[3] - rec[1]);
        xmin = min(xmin, rec[0]);
        ymin = min(ymin, rec[1]);
        xmax = max(xmax, rec[2]);
        ymax = max(ymax, rec[3]);
    }
    if (mp[PII(xmin, ymin)] != 1 || mp[PII(xmin, ymax)] != 1 || mp[PII(xmax, ymin)] != 1 || mp[PII(xmax, ymax)] != 1) return false;
    mp.erase(PII(xmin, ymin));
    mp.erase(PII(xmin, ymax));
    mp.erase(PII(xmax, ymin));
    mp.erase(PII(xmax, ymax));
    for (auto &&[point, cnt] : mp) {
        if (cnt == 2 || cnt == 4) continue;
        return false;
    }
    return (xmax - xmin) * (ymax - ymin) == sum;
}

int main() {
    return 0;
}
