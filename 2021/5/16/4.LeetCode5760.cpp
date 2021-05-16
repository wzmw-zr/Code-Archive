/*************************************************************************
	> File Name: 4.LeetCode5760.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月16日 星期日 10时36分05秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int minSwaps(string s) {
    vector<int> cnt(2, 0);
    for (int i = 0; s[i]; i++) cnt[s[i] - '0']++;
    if (abs(cnt[0] - cnt[1]) > 1) return -1;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0, t = 0; s[i]; i++, t = !t) {
        if (s[i] - '0' == t) continue;
        cnt1++;
    }
    for (int i = 0, t = 1; s[i]; i++, t = !t) {
        if (s[i] - '0' == t)  continue;
        cnt2++;
    }
    int ans = INT32_MAX;
    if (!(cnt1 & 1)) ans = min(ans, cnt1 / 2);
    if (!(cnt2 & 1)) ans = min(ans, cnt2 / 2);
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << minSwaps(s) << endl;
    return 0;
}
