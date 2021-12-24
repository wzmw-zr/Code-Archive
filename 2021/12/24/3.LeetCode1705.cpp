/*************************************************************************
	> File Name: 3.LeetCode1705.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月24日 星期五 10时18分30秒
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
    priority_queue<PII, vector<PII>, greater<PII>> que;
    int ind = 0, cur = 1, ans = 0;
    while (ind < n || !que.empty()) {
        if (ind < n && apples[ind] > 0 && days[ind] > 0) que.push(PII(ind + days[ind], apples[ind]));
        while (!que.empty() && que.top().first < cur) que.pop();
        while (!que.empty() && que.top().second == 0) que.pop();
        if (!que.empty()) {
            auto temp = que.top();
            que.pop();
            if (--temp.second) que.push(temp);
            ans++;
        }
        ind++, cur++;
    }
    return ans;
}

int main() {
    return 0;
}
