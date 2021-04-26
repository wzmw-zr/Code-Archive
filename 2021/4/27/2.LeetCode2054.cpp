/*************************************************************************
	> File Name: 2.LeetCode2054.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月27日 星期二 00时11分02秒
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

vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
    int n = big.size();
    int cnt = small.size();
    unordered_map<int, int> mp;
    for (int &x : small) mp[x] = 0;
    int l = 0, r = 0;
    int min_len = INT32_MAX;
    int x = -1, y = -1;
    while (r < n) {
        if (mp.count(big[r])) {
            if (!mp[big[r]]) cnt--;
            mp[big[r]]++;
        }
        while (cnt == 0) {
            if (mp.count(big[l])) {
                if (!(--mp[big[l]])) {
                    if (r - l + 1 < min_len) x = l, y = r, min_len = r - l + 1;
                    cnt++;
                    l++;
                    break;
                }
            }
            l++;
        }
        r++;
    }
    while (cnt == 0) {
        if (mp.count(big[l])) {
            if (!(--mp[big[l]])) {
                if (r - l + 1 < min_len) x = l, y = r, min_len = r - l + 1;
                cnt++;
                l++;
                break;
            }
        }
        l++;
    }
    if (x == -1) return vector<int>(0);
    return {x, y};
}

int main() {
    return 0;
}
