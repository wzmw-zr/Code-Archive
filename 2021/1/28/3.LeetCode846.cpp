/*************************************************************************
	> File Name: 3.LeetCode846.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月28日 星期四 18时51分05秒
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

bool isNStraightHand(vector<int>& hand, int W) {
    int n = hand.size();
    if (n % W) return false;
    map<int, int> mp;
    for (int &x : hand) mp[x]++;
    for (auto &&[x, cnt] : mp) {
        if (cnt == 0) continue;
        while (cnt) {
            for (int i = 0; i < W; i++) {
                if (mp.count(x + i) && mp[x + i]) mp[x + i]--;
                else return false;
            }
        }
    }
    return true;
}

int main() {
    return 0;
}
