/*************************************************************************
	> File Name: 3.LeetCode5919.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月07日 星期日 10时47分06秒
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
#include <cstring>
#include <cstdlib>
using namespace std;

long long countVowels(string word) {
    int wzmw_zr_q2 = 0;
    int n = word.size();
    long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    unordered_set<char> st({'a', 'e', 'i', 'o', 'u'});
    for (int i = 0; word[i]; i++) {
        if (st.count(word[i])) dp[i + 1] = (i + 1) + dp[i];
        else dp[i + 1] = dp[i];
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) ans += dp[i];
    return ans;
}

int main() {
    string word;
    cin >> word;
    cout << countVowels(word) << endl;
    return 0;
}
