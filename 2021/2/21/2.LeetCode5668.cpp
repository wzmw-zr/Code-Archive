/*************************************************************************
	> File Name: 2.LeetCode5668.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月21日 星期日 00时36分05秒
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

bool check(string &s, int x, int y) {
    vector<int> lower(26, 0), upper(26, 0);
    for (int i = x; i <= y; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') lower[s[i] - 'a']++;
        else upper[s[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if ((lower[i] && upper[i]) || (!lower[i] && !upper[i])) continue;
        return false;
    }
    return true;
}

string longestNiceSubstring(string s) {
    int n = s.size(), len = 0, ind = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (!check(s, j, j + i - 1)) continue;
            len = i, ind = j;
            break;
        }
    }
    return s.substr(ind, len);
}

int main() {
    return 0;
}
