/*************************************************************************
	> File Name: 1.LeetCode1846.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月15日 星期四 00时04分48秒
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

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int ans = 0;
    int n = arr.size();
    int num = 1;
    for (int x : arr) {
        ans = min(num, x);
        if (num <= x) num++;
    }
    return ans;
}

int main() {
    return 0;
}
