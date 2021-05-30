/*************************************************************************
	> File Name: 4.LeetCode5774.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月30日 星期日 10时48分55秒
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

struct Server {
    int ind;
    int val;

    Server() = default;
    Server(int ind, int val) : ind(ind), val(val) {}

    bool operator<(const Server &that) const {
        return this->val == that.val ? this->ind > that.ind : this->val > that.val;
    }
};

vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    int n = servers.size();
    int m = tasks.size();
    priority_queue<Server> server_que;
    priority_queue<int, vector<int>, greater<int>> task_que;
    vector<int> ans(m);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) server_que.push(Server(i, servers[i]));
    for (int i = 0; i < m; i++) task_que.push(i);
    int i = 0;
    while (1) {
        if (mp.count(i)) {
            for (int x : mp[i]) server_que.push(Server(x, servers[x]));
            mp.erase(i);
        }
        while (!server_que.empty() && !task_que.empty() && task_que.top() <= i) {
            int t_ind = task_que.top();
            task_que.pop();
            Server server = server_que.top();
            server_que.pop();
            ans[t_ind] = server.ind;
            int t = i + tasks[t_ind];
            if (!mp.count(t)) mp[t] = vector<int>();
            mp[t].push_back(server.ind);
        }
        i++;
        if (task_que.empty()) break;
    }
    return ans;
}

int main() {
    return 0;
}
