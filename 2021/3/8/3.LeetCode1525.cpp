/*************************************************************************
	> File Name: 3.LeetCode1525.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月08日 星期一 13时37分07秒
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

int numSplits(string s) {
    int n = s.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    unordered_map<char, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        mp1[s[i]]++;
        left[i] = mp1.size();
    }
    for (int i = n - 1; i >= 0; i--) {
        mp2[s[i]]++;
        right[i] = mp2.size();
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (left[i - 1] == right[i]) ans++;
    }
    return ans;
}

int main() {
    return 0;
}
