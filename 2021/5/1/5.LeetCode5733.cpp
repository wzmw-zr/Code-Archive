/*************************************************************************
	> File Name: 5.LeetCode5733.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月01日 星期六 22时50分19秒
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


// WA

int bs_first_ge(vector<int> &sizes, int num) {
    int l = 0, r = sizes.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (sizes[mid] >= num) r = mid;
        else l = mid + 1;
    }
    return l;
}

vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
    int ind = 0;
    auto cmp = [](vector<int> &a, vector<int> &b) {
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    };
    sort(rooms.begin(), rooms.end(), cmp);
    unordered_map<int, vector<int>> mp;
    unordered_set<int> st;
    for (auto &x : rooms) {
        if (!mp.count(x[1])) mp[x[1]] = vector<int>(0);
        mp[x[1]].push_back(x[0]);
        st.insert(x[1]);
    }
    vector<int> sizes(0);
    for (int x : st) sizes.push_back(x);
    int n = sizes.size();
    sort(sizes.begin(), sizes.end());
    vector<int> ans;
    for (auto &q : queries) {
        int ind = bs_first_ge(sizes, q[1]);
        if (ind == n) {
            ans.push_back(-1);
            continue;
        }
        int dis = INT32_MAX;
        int t_ind = 1;
        for (int i = ind; i < n; i++) {
            for (int x : mp[i]) {
                int temp = abs(x - q[0]);
                if (dis < temp) dis = temp, t_ind = x;
                else if (dis == temp) t_ind = min(t_ind, x);
                else continue;
            }
        }
        ans.push_back(t_ind);
    }
    return ans;
}

int main() {
    return 0;
}
