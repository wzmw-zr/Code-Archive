/*************************************************************************
	> File Name: 1.LeetCode690.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月01日 星期六 00时04分13秒
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

struct Employee {
    int id;
    int importance;
    vector<int> subordinates;
};

void dfs(int id, unordered_set<int> &st, unordered_map<int, Employee *> &mp) {
    st.insert(id);
    for (auto x : mp[id]->subordinates) dfs(x, st, mp);
}

int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> mp;
    unordered_set<int> st;
    for (auto x : employees) mp[x->id] = x;
    dfs(id, st, mp);
    int ans = 0;
    for (auto x : st) ans += mp[x]->importance;
    return ans;
}

int main() {
    return 0;
}
