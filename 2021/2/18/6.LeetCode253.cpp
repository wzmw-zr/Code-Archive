/*************************************************************************
	> File Name: 6.LeetCode253.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月18日 星期四 23时36分01秒
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

int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> que;
    int ans = 0;
    for (auto &x : intervals) {
        while (!que.empty() && x[0] >= que.top()) que.pop();
        que.push(x[1]);
        ans = max(ans, (int) que.size());
    }
    return ans;
}

int main() {
    return 0;
}
