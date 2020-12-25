/*************************************************************************
	> File Name: 2.LeetCode636.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月25日 星期五 08时31分53秒
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

struct Task {
    int id;
    int time;
    int status;
    Task() = default;
    Task(int id, int time, int status) : id(id), time(time), status(status) {}
};

Task sparse(string s) {
    string id, status, time;
    int ind_1 = s.find(':', 0);
    id = s.substr(0, ind_1);
    int ind_2 = s.find(':', ind_1 + 1);
    status = s.substr(ind_1 + 1, ind_2 - ind_1 - 1);
    time = s.substr(ind_2 + 1);
    return Task(stoi(id), stoi(time), (status == "start" ? 0 : 1));
}

vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> ans(n, 0);
    stack<Task> st;
    int used_time = 0;
    for (string s : logs) {
        Task temp = sparse(s);
        if (!st.size() || st.top().id != temp.id || (st.top().id == temp.id) && (!st.top().status && !temp.status)) {
            st.push(temp);
        } else {
            Task x = st.top();
            st.pop();
            int t = temp.time - x.time + 1 - used_time;
            ans[temp.id] += t;
            used_time = temp.time - x.time + 1;
        }
    }
    return ans;
}

int main() {
    return 0;
}
