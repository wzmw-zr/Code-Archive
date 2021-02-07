/*************************************************************************
	> File Name: 2.LeetCode424.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月04日 星期四 00时42分38秒
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

int characterReplacement(string s, int k) {
    int n = s.size();
    vector<vector<int>> cnt(n + 1, vector<int>(26, 0));
    int ans = min(k, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) cnt[i + 1][j] = cnt[i][j];
        cnt[i + 1][s[i] - 'A']++;
    }
    int l = 1, r = k + 1;
    while (r <= n) {
        int max_cnt = 0;
        for (int i = 0; i < 26; i++) 
            max_cnt = max(max_cnt, cnt[r][i] - cnt[l - 1][i]);
        if (max_cnt + k >= r - l + 1) ans = max(ans, r - l + 1), r++;
        else l++;
    }
    return ans;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << characterReplacement(s, k) << endl;
    return 0;
}
