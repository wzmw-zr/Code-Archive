/*************************************************************************
	> File Name: 1.LeetCode1046.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月03日 星期四 10时10分58秒
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

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> que;
    for (int x : stones) que.push(x);
    while (!que.empty()) {
        int stone_1 = que.top();
        que.pop();
        if (que.empty()) return stone_1;
        int stone_2 = que.top();
        que.pop();
        if (stone_1 == stone_2) continue;
        que.push((int) abs(stone_1 - stone_2));
    }
    return 0;
}

int main() {
    return 0;
}
