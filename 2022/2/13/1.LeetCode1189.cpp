/*************************************************************************
	> File Name: 1.LeetCode1189.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月13日 星期日 00时03分03秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int maxNumberOfBalloons(string text) {
    vector<int> cnt(26, 0);
    for (char c : text) {
        cnt[c - 'a']++;
    }
    return min({cnt[0], cnt[1], cnt['l' - 'a'] / 2, cnt['o' - 'a'] / 2, cnt['n' - 'a']});
}

int main() {
    return 0;
}
