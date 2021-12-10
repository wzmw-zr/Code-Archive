/*************************************************************************
	> File Name: 1.LeetCode748.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月10日 星期五 08时39分59秒
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

string shortestCompletingWord(string licensePlate, vector<string>& words) {
    vector<int> cnts(26, 0);
    for (char c : licensePlate) {
        if (c >= 'a' && c <= 'z') cnts[c - 'a']++;
        if (c >= 'A' && c <= 'Z') cnts[c - 'A']++;
    }
    string ans = "";
    for (auto word : words) {
        vector<int> temp(26, 0);
        for (char c : word) {
            if (c >= 'a' && c <= 'z') temp[c - 'a']++;
            if (c >= 'A' && c <= 'Z') temp[c - 'A']++;
        }
        int flag = 0;
        for (int i = 0; i < 26; i++) {
            if (temp[i] >= cnts[i]) continue;
            flag = 1;
            break;
        }
        if (!flag && (ans.size() == 0 || ans.size() > word.size())) ans = word;
    }
    return ans;
}

int main() {
    return 0;
}
