/*************************************************************************
	> File Name: 1.LeetCode1738.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月19日 星期三 00时02分57秒
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

int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int n = matrix.size(), m = matrix[0].size(); 
    vector<vector<int>> pre(2, vector<int>(m + 1, 0));
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < n; i++) {
        int ind = i & 1;
        for (int j = 0; j < m; j++) {
            pre[ind][j + 1] = matrix[i][j] ^ pre[!ind][j] ^ pre[!ind][j + 1] ^ pre[ind][j];
            if (que.size() < k) que.push(pre[ind][j + 1]);
            else {
                if (pre[ind][j + 1] <= que.top()) continue;
                que.pop();
                que.push(pre[ind][j + 1]);
            }
        }
    }
    return que.top();
}

int main() {
    return 0;
}
