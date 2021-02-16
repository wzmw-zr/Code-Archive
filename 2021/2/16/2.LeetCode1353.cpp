/*************************************************************************
	> File Name: 2.LeetCode1353.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月16日 星期二 23时29分16秒
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

#define MAX_N 100000

int maxEvents(vector<vector<int>>& events) {
    vector<vector<int>> days(MAX_N + 5);
    int n = events.size(), cnt = 0;
    for (int i = 0; i < n; i++) days[events[i][0]].push_back(i);
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 1; i <= MAX_N; i++) {
        for (int &ind : days[i]) que.push(events[ind][1]);
        while (!que.empty() && que.top() < i) que.pop();
        if (!que.empty()) {
            que.pop();
            cnt++;
        }
    }
    return cnt;
}

int main() {
    return 0;
}
