/*************************************************************************
	> File Name: 5.LeetCode6006.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月13日 星期日 11时12分43秒
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

long long minimumRemoval(vector<int>& beans) {
    long ans = INT64_MAX;
    long n = 0;
    for (int x : beans) {
        n += x;
    }
    long cnt = 0;
    map<long, long> mp;
    for (long x : beans) {
        mp[x]++;
    }
    for (auto iter = mp.rbegin(); iter != mp.rend(); iter++) {
        cnt += iter->second;
        ans = min(ans, n - iter->first * cnt);
    }
    return ans;
}

int main() {
    return 0;
}
