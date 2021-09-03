/*************************************************************************
	> File Name: 2.LeetCode2321.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月03日 星期五 08时29分51秒
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

vector<int> smallestK(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, less<int>> que;
    for (int x : arr) {
        if (que.size() < k) que.push(x);
        else if (!que.empty() && que.top() > x) {
            que.pop();
            que.push(x);
        }
    }
    vector<int> ans;
    while (!que.empty()) {
        ans.push_back(que.top());
        que.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}
