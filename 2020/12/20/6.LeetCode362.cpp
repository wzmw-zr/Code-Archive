/*************************************************************************
	> File Name: 6.LeetCode362.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月20日 星期日 18时51分50秒
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

class HitCounter {
public:
    priority_queue<int, vector<int>, greater<int>> que;
    //unordered_map<int, int> mp;
    HitCounter() {}

    void hit(int timestamp) {
        while (!que.empty() && (timestamp - que.top() >= 300)) que.pop();
        que.push(timestamp);
        //mp[timestamp]++;
    }

    int getHits(int timestamp) {
        while (!que.empty() && (timestamp - que.top() >= 300)) que.pop();
        return que.size();
        #if 0
        int ans = 0;
        for (int i = 0; i < 300; i++) {
            if (!mp.count(timestamp - i)) continue;
            ans += mp[timestamp - i];
        }
        return ans;
        #endif
    }
};

int main() {
    return 0;
}
