/*************************************************************************
	> File Name: 1.LeetCode659.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月04日 星期五 08时03分02秒
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

typedef priority_queue<int, vector<int>, greater<int>> Minque;

bool isPossible(vector<int>& nums) {
    unordered_map<int, Minque> mp;
    for (int x : nums) {
        if (!mp.count(x - 1)) {
            if (!mp.count(x)) mp[x] = Minque();
            mp[x].push(1);
            continue;
        }
        int temp = mp[x - 1].top();
        mp[x - 1].pop();
        if (mp[x - 1].size() == 0) mp.erase(mp.find(x - 1));
        if (!mp.count(x)) mp[x] = Minque();
        mp[x].push(temp + 1);
    }
    for (auto &x : mp) {
        if (x.second.empty()) continue;
        if (x.second.top() < 3) return false;
    }
    return true;
}

int main() {
    return 0;
}
