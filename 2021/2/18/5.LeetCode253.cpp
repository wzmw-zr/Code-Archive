/*************************************************************************
	> File Name: 5.LeetCode253.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月18日 星期四 22时55分18秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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

#define MAX_N 1000000

int minMeetingRooms(vector<vector<int>>& intervals) {
    int pre[MAX_N + 10];
    memset(pre, 0, sizeof(pre));
    for (auto &x : intervals) pre[x[0] + 1]++, pre[x[1] + 1]--;
    int ans = 0;
    for (int i = 1; i <= MAX_N; i++) {
        pre[i] += pre[i - 1];
        ans = max(ans, pre[i]);
    }
    return ans;
}

int main() {
    return 0;
}
