/*************************************************************************
	> File Name: 1.LeetCode171.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月30日 星期五 00时08分00秒
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
#include <cmath>
using namespace std;

int titleToNumber(string columnTitle) {
    int n = columnTitle.size();
    int ans = 0;
    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
        ans += int(pow(26, j)) * (int(columnTitle[i] - 'A') + 1);
    }
    return ans;
}

int main() {
    return 0;
}
