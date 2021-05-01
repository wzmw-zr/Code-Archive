/*************************************************************************
	> File Name: 1.LeetCode554.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月02日 星期日 00时05分45秒
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

int leastBricks(vector<vector<int>>& wall) {
    unordered_map<long, int> mp;
    for (auto &x : wall) {
        long pos = 0;
        for (long y : x) {
            if (pos) mp[pos]++;
            pos += y;
        }
    }
    int n = wall.size();
    int mmax = 0;
    for (auto &&[pos, cnt] : mp)  mmax = max(mmax, cnt);
    return n - mmax;
}

int main() {
    return 0;
}
