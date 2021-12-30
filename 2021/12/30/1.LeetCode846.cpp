/*************************************************************************
	> File Name: 1.LeetCode846.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月30日 星期四 09时25分52秒
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

bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();
    if (n % groupSize) return false;
    map<int, int> mp;
    for (int x : hand) mp[x]++;
    while (mp.size()) {
        int t = mp.begin()->first;
        for (int i = 0; i < groupSize; i++) {
            if (!mp.count(t + i)) return false;
            if (!(--mp[t + i])) mp.erase(t + i);
        }
    }
    return true;
}

int main() {
    return 0;
}
