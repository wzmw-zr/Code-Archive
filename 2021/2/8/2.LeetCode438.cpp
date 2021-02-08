/*************************************************************************
	> File Name: 2.LeetCode438.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月08日 星期一 23时41分38秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int n = s.size(), m = p.size();
    int cnt[n + 1][26];
    int num[26];
    memset(cnt, 0, sizeof(cnt));
    memset(num, 0, sizeof(num));
    for (int i = 0; s[i]; i++) {
        for (int j = 0; j < 26; j++) cnt[i + 1][j] = cnt[i][j];
        cnt[i + 1][s[i] - 'a']++;
    }
    for (int i = 0; p[i]; i++) num[p[i] - 'a']++;
    for (int i = 0; i + m - 1 < n; i++) {
        int flag = 0;
        for (int j = 0; j < 26; j++) {
            int temp = cnt[i + m][j] - cnt[i][j];
            if (temp == num[j]) continue;
            flag = 1;
            break;
        }
        if (!flag) ans.push_back(i);
    }
    return ans;
}


int main() {
    return 0;
}
