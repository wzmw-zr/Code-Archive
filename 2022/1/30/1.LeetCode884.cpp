/*************************************************************************
	> File Name: 1.LeetCode884.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月30日 星期日 09时28分25秒
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
#include <sstream>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

vector<string> uncommonFromSentences(string s1, string s2) {
    istringstream sin1(s1);
    istringstream sin2(s2);
    unordered_map<string, int> mp1;
    unordered_map<string, int> mp2;
    string word;
    while (sin1 >> word) {
        mp1[word]++;
    }
    while (sin2 >> word) {
        mp2[word]++;
    }
    vector<string> ans;
    for (auto &&[w, cnt] : mp1) {
        if (cnt != 1 || mp2.count(w)) {
            continue;
        }
        ans.push_back(w);
    }
    for (auto &&[w, cnt] : mp2) {
        if (cnt != 1 || mp1.count(w)) {
            continue;
        }
        ans.push_back(w);
    }
    return ans;
}

int main() {
    return 0;
}
