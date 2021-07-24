/*************************************************************************
	> File Name: 3.LeetCode5806.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月24日 星期六 22时57分34秒
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

// WA
vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    vector<long long> diff(1e5 + 5, 0);
    for (auto seg : segments) {
        diff[seg[0]] += static_cast<long long>(seg[2]);
        diff[seg[1]] -= static_cast<long long>(seg[2]);
    }
    for (int i = 1; i <= 1e5; i++) diff[i] += diff[i - 1];
    long long pre_color = diff[1];
    vector<vector<long long>> ans;
    for (int left = 1, right = 1; right <= 1e5; right++) {
        if (diff[right] == 0) {
            if (pre_color == 0) continue;
            ans.push_back(vector<long long>{left, right, pre_color});
            pre_color = 0;
        } else {
            if (pre_color == diff[right]) continue;
            if (pre_color != 0) ans.push_back(vector<long long>{left, right, pre_color});
            left = right;
            pre_color = diff[right];
        }
    }
    return ans;
}

int main() {
    return 0;
}
