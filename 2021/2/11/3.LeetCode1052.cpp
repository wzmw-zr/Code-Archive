/*************************************************************************
	> File Name: 3.LeetCode1052.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月11日 星期四 09时11分38秒
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

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int n = customers.size(), l = 0, r = 0, ans = 0, total = 0;
    for (int i = 0; i < n; i++) total += customers[i] * !grumpy[i];
    while (r < X - 1) {
        if (grumpy[r]) total += customers[r];
        r++;
    }
    while (r < n) {
        if (grumpy[r]) total += customers[r];
        ans = max(ans, total);
        if (grumpy[l]) total -= customers[l];
        l++, r++;
    }
    return ans;
}

int main() {
    return 0;
}
