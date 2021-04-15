/*************************************************************************
	> File Name: 2.LeetCode2036.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月15日 星期四 22时57分16秒
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

vector<int> smallestK(vector<int>& arr, int k) {
    priority_queue<int> que;
    for (int &x : arr) {
        if ((int) que.size() < k) que.push(x);
        else {
            if (que.empty()) continue;
            if (que.top() <= x) continue;
            que.pop();
            que.push(x);
        }
    }
    vector<int> ans(k);
    for (int i = k - 1; i >= 0; i--) {
        ans[i] = que.top();
        que.pop();
    }
    return ans;
}

int main() {
    return 0;
}
