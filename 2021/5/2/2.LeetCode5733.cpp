/*************************************************************************
	> File Name: 2.LeetCode5733.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月02日 星期日 00时34分44秒
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

vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
    int q = queries.size();
    vector<int> ans(q);
    vector<int> order(q);
    for (int i = 0; i < q; i++) order[i] = i;
    sort(order.begin(), order.end(), [&](int i, int j){
        return queries[i][1] > queries[j][1];
    });
    int n = rooms.size();
    sort(rooms.begin(), rooms.end(), [](vector<int> &a, vector<int> &b){
        return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];
    });
    int ptr = -1;
    set<int> s;
    for (int i : order) {
        while (ptr + 1 < n && rooms[ptr + 1][1] >= queries[i][1]) {
            s.insert(rooms[++ptr][0]);
        }
        if (s.empty()) 
            ans[i] = -1;
        else {
            int p = queries[i][0];
            auto it = s.lower_bound(p);
            if (it != s.begin() && (it == s.end() || p - *prev(it) <= *it - p)) ans[i] = *prev(it);
            else ans[i] = *it;
        }
    }
    return ans;
}

int main() {
    return 0;
}
