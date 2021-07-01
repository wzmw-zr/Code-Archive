/*************************************************************************
	> File Name: 1.LeetCode1833.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月02日 星期五 00时01分29秒
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

int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int ans = 0;
    for (int x : costs) {
        if (coins < x) break;
        coins -= x;
        ans++;
    }
    return ans;
}

int main() {
    return 0;
}
