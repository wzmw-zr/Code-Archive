/*************************************************************************
	> File Name: 2.LeetCode5868.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月12日 星期日 10时33分35秒
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

long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    unordered_map<double, long long> mp;
    long long ans = 0;
    for (auto rec : rectangles) mp[(1.0 * rec[0]) / (1.0 * rec[1])]++;
    for (auto &&[ratio, cnt] : mp) ans += cnt * (cnt - 1) / 2;
    return ans;
}

int main() {
    return 0;
}
