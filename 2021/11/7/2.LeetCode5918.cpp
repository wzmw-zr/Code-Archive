/*************************************************************************
	> File Name: 2.LeetCode5918.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月07日 星期日 10时33分00秒
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
using namespace std;

bool check(string &s, int l, int r) {
    unordered_map<char, int> mp({{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}});
    for (int i = l; i <= r; i++) {
        if (!mp.count(s[i])) return false;
        mp[s[i]]++;
    }
    for (auto &&[c, cnt] : mp) {
        if (cnt) continue;
        return false;
    }
    return true;
}

int countVowelSubstrings(string word) {
    int wzmw_zr_q1 = 0;
    int n = word.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (check(word, i, j)) ans++;
        }
    }
    return ans;
}

int main() {
    string word;
    cin >> word;
    cout << countVowelSubstrings(word) << endl;
    return 0;
}
