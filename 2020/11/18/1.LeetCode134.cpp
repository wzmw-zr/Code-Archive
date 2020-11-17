/*************************************************************************
	> File Name: 1.LeetCode134.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月18日 星期三 00时07分43秒
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

int check(vector<int> &gas, vector<int> &cost, int ind) {
    int n = gas.size();
    int start = (ind + 1) % n;
    int oil = gas[ind] - cost[ind];
    while (start != ind) {
        oil += gas[start] - cost[start];
        if (oil < 0) return 0;
        start = (start + 1) % n;
    }
    return 1;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    for (int i = 0; i < n; i++) {
        if (gas[i] < cost[i]) continue;
        if (check(gas, cost, i)) return i;
    }
    return -1;
}

int main() {
    return 0;
}
