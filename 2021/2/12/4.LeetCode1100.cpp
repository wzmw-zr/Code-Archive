/*************************************************************************
	> File Name: 4.LeetCode1100.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月12日 星期五 09时00分50秒
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

bool check(vector<int> &cnt) {
    for (int &x : cnt) {
        if (x > 1) return false;
    }
    return true;
}

int numKLenSubstrNoRepeats(string S, int K) {
    if (K > S.size()) return 0;
    vector<int> cnt(26, 0);
    int n = S.size(), ans = 0;
    for (int i = 0; i < K - 1; i++) cnt[S[i] - 'a']++;
    for (int i = K - 1; S[i]; i++) {
        cnt[S[i] - 'a']++;
        if (check(cnt)) ans++;
        cnt[S[i - K + 1] - 'a']--;
    }
    return ans;
}

int main() {
    return 0;
}
