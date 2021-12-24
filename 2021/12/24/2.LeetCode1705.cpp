/*************************************************************************
	> File Name: 2.LeetCode1705.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月24日 星期五 09时25分22秒
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

using PII = pair<int, int>;

int eatenApples(vector<int>& apples, vector<int>& days) {
    int n = apples.size();
    int cur = 1;
    int ans = 0;
    priority_queue<PII, vector<PII>, greater<PII>> que;
    for (int i = 0; i < n; i++) {
        que.push(PII(i + days[i], min(days[i], apples[i])));
        while (!que.empty() && que.top().first < (i + 1)) que.pop();
        while (!que.empty() && que.top().second == 0) que.pop();
        if (!que.empty()) {
            auto temp = que.top();
            que.pop();
            if (--temp.second) que.push(temp);
            ans++;
        }
        cur = i + 2;
    }
    while (!que.empty()) {
        auto temp = que.top(); 
        que.pop();
        if (temp.first < cur) continue;
        int cnt = min(temp.first - cur + 1, temp.second);
        cur += cnt;
        ans += cnt;
    }
    return ans;
}

int main() {
    return 0;
}
