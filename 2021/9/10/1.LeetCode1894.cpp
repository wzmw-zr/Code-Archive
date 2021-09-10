/*************************************************************************
	> File Name: 1.LeetCode1894.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月10日 星期五 08时40分10秒
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

int chalkReplacer(vector<int>& chalk, int k) {
    int n = chalk.size();
    long num = k;
    vector<long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + chalk[i];
    num %= pre[n];
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (pre[mid] > num) r = mid;
        else l = mid + 1;
    }
    return l - 1;
}

int main() {
    return 0;
}
