/*************************************************************************
	> File Name: 4.LeetCode1701.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月09日 星期六 01时10分02秒
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

double averageWaitingTime(vector<vector<int>>& customers) {
    int clock = 0;
    double wait_time = 0;
    for (auto &x : customers) {
        if (x[0] <= clock) {
            clock += x[1];
            wait_time += clock - x[0];
        } else {
            clock = x[0] + x[1];
            wait_time += x[1];
        }
    }
    return wait_time / customers.size();
}

int main() {
    return 0;
}
