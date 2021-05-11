/*************************************************************************
	> File Name: 1.LeetCode1310.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月12日 星期三 00时02分39秒
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

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) 
        pre[i + 1] = pre[i] ^ arr[i];
    vector<int> ans;
    for (auto q : queries) 
        ans.push_back(pre[q[1] + 1] ^ pre[q[0]]);
    return ans;
}

int main() {
    return 0;
}
