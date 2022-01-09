/*************************************************************************
	> File Name: 1.LeetCode1629.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月09日 星期日 09时07分47秒
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

char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    map<int, set<char>> mp;
    int n = releaseTimes.size();
    int ind = 0;
    for (int i = 0; i < n; i++) {
        int t = releaseTimes[i] - ind;
        ind = releaseTimes[i];
        if (!mp.count(t)) mp[t] = set<char>();
        mp[t].insert(keysPressed[i]);
    }
    return *((mp.rbegin()->second).rbegin());
}

int main() {
    return 0;
}
