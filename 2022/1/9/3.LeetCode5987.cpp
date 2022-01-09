/*************************************************************************
	> File Name: 3.LeetCode5987.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月09日 星期日 11时02分26秒
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

int wordCount(vector<string>& startWords, vector<string>& targetWords) {
    unordered_map<string, int> mp;
    for (auto word : targetWords) {
        sort(word.begin(), word.end());
        mp[word]++;
    }
    unordered_set<string> res;
    for (auto word : startWords) {
        unordered_set<char> st_t;
        for (char c : word) st_t.insert(c);
        for (char c = 'a'; c <= 'z'; c++) {
            if (st_t.count(c)) continue;
            string temp = word + c;
            sort(temp.begin(), temp.end());
            if (mp.count(temp)) res.insert(temp);
        }
    }
    int ans = 0;
    for (auto s : res) ans += mp[s];
    return ans;
}

int main() {
    return 0;
}
