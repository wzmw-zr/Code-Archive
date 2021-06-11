/*************************************************************************
	> File Name: 3.LeetCode1492.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月11日 星期五 23时06分52秒
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

int kthFactor(int n, int k) {
    int ans = -1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i) continue;
        ans = i;
        if ((++cnt) == k) break;
    }
    return cnt == k ? ans : -1;
}

int main() {
    return 0;
}
