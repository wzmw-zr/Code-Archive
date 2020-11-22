/*************************************************************************
	> File Name: 6.LeetCode5608.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月22日 星期日 11时30分57秒
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

int minimumEffort(vector<vector<int>>& tasks) {
    int n = tasks.size();
    int ans = 0;
    vector<int> dis(n);
    for (int i = 0; i < n; i++) {
        dis[i] = tasks[i][1] - tasks[i][0];   
        ans += tasks[i][0];
    }
    sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){ return a[1] < b[1]; });
    sort(dis.begin(), dis.end());
    ans += dis[0];
    ans = max(ans, tasks[n - 1][1]);
    return ans;
}

int main() {
    return 0;
}
