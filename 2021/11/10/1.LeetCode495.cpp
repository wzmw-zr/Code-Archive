/*************************************************************************
	> File Name: 1.LeetCode495.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月10日 星期三 10时27分21秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int sum = 0;
    int n = timeSeries.size();
    for (int i = 1; i < n; i++) {
        if (timeSeries[i] - duration >= timeSeries[i - 1]) sum += duration;
        else sum += timeSeries[i] - timeSeries[i - 1];
    }
    sum += duration;
    return sum;
}

int main() {
    return 0;
}
