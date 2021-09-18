/*************************************************************************
	> File Name: 4.LeetCode5860.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月18日 星期六 23时24分26秒
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

vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    if (n & 1) return {};
    map<int, int> mp;
    sort(changed.begin(), changed.end());
    for (int x : changed) mp[x]++;
    vector<int> ans;
    for (auto [x, cnt] : mp) {
        if (cnt == 0) continue;
        if (!mp.count(x * 2) || mp[x * 2] < cnt) return {};
        if (x != 0) {
            for (int i = 0; i < cnt; i++) ans.push_back(x);
            mp[x] -= cnt;
            mp[x * 2] -= cnt;
        } else {
            if (cnt & 1) return {};
            for (int i = 0; i < cnt / 2; i++) ans.push_back(x);
            mp[x] -= cnt;
        }
    }
    return ans;
}

int main() {
    return 0;
}
