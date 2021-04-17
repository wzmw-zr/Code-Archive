/*************************************************************************
	> File Name: 3.LeetCode5718.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月17日 星期六 22时33分30秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
    vector<int> ans;
    for (auto &q : queries) {
        int cnt = 0;
        for (auto &p : points) {
            int dis = (q[0] - p[0]) * (q[0] - p[0]) + (q[1] - p[1]) * (q[1] - p[1]);
            if (dis <= q[2] * q[2]) cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main() {
    return 0;
}
