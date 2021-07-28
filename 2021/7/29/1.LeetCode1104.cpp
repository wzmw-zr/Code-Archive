/*************************************************************************
	> File Name: 1.LeetCode1104.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月29日 星期四 00时07分07秒
 ************************************************************************/

#include <iostream>
#include <cmath>
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

int update(int label) {
    int level = int(log2(label * 1.0)) + 1;
    int first = int(exp2(level - 1));
    int dis = label - first + 1;
    label = first - (dis + 1) / 2;
    return label;
}

vector<int> pathInZigZagTree(int label) {
    vector<int> ans;
    while (label) {
        ans.push_back(label);
        label = update(label);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}
