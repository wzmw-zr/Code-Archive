/*************************************************************************
	> File Name: 2.LeetCode5916.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月31日 星期日 10时39分49秒
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

int minimumOperations(vector<int>& nums, int start, int goal) {
    int wzmw_zr_q3 = 0;
    using PII = pair<long, int>;
    vector<int> check(1010, 0);
    queue<PII> que;
    que.push(PII(start, 0));
    check[start] = 1;
    while (!que.empty()) {
        auto temp = que.front();
        que.pop();
        if (temp.first == goal) return temp.second;
        for (int x : nums) {
            if (temp.first + x == goal) return temp.second + 1;
            if ((temp.first + x >= 0) && (temp.first + x <= 1000) && (!check[temp.first + x])) {
                check[temp.first + x] = 1;
                que.push(PII(temp.first + x, temp.second + 1));
            } 
            if (temp.first - x == goal) return temp.second + 1;
            if ((temp.first - x <= 1000) && (temp.first - x >= 0) && (!check[temp.first - x])) {
                check[temp.first - x] = 1;
                que.push(PII(temp.first - x, temp.second + 1));
            }
            if ((temp.first ^ x) == goal) return temp.second + 1;
            if (((temp.first ^ x) >= 0) && ((temp.first ^ x) <= 1000) && (!check[(temp.first ^ x)]))  {
                check[(temp.first ^ x)] = 1;
                que.push(PII((temp.first ^ x), temp.second + 1));
            }
        }
    }
    return -1;
}

int main() {
    return 0;
}
