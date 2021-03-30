/*************************************************************************
	> File Name: 6.LeetCode950.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月30日 星期二 21时06分45秒
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


vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    vector<int> ans(n);
    sort(deck.begin(), deck.end());
    queue<int> que;
    for (int i = 0; i < n; i++) que.push(i);
    int cnt = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        ans[temp] = deck[cnt++];
        if (que.empty()) break;
        que.push(que.front());
        que.pop();
    }
    return ans;
}

int main() {
    return 0;
}
