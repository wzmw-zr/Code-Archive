/*************************************************************************
	> File Name: 4.LeetCode5682.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月06日 星期六 22时47分37秒
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

int get_dis(vector<int> &cnt) {
    int mmin = INT32_MAX, mmax = INT32_MIN;
    for (int &x : cnt) {
        if (x == 0) continue;
        mmin = min(mmin, x);
        mmax = max(mmax, x);
    }
    return mmax - mmin;
}

int beautySum(string s) {
    int n = s.size();
    int ans = 0;
    for (int l = 2; l <= n; l++) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < l - 1; i++) cnt[s[i] - 'a']++;
        for (int i = l - 1; i < n; i++) {
            cnt[s[i] - 'a']++;
            ans += get_dis(cnt);
            cnt[s[i - l + 1] - 'a']--;
        }
    }
    return ans;
}

int main() {
    return 0;
}
