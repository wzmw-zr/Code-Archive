/*************************************************************************
	> File Name: 5.LeetCode1958.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月11日 星期四 09时40分59秒
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

bool check(unordered_map<int, int> &mp, unordered_map<int, int> &cnt) {
    for (auto &&[x, num] : mp) {
        if (!cnt.count(x)) return false;
        if (cnt[x] < num) return false;
    }
    return true;
}

vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
    unordered_map<int, int> mp, cnt;
    for (int &x : small) mp[x]++;
    int n = big.size(), l = 0, r = 0;
    vector<int> ans({0, INT32_MAX});
    while (r < small.size() - 1) cnt[big[r]]++;
    while (r < n) {
        cnt[big[r]]++;
        if (check(mp, cnt)) {
            if (ans[1] - ans[0] > r - l) ans[0] = l, ans[1] = r;
        }
        while (cnt[big[l]] > mp[big[l]]) cnt[big[l]]--, l++;
        r++;
    }
    return ans;
}

int main() {
    return 0;
}
