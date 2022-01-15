/*************************************************************************
	> File Name: 1.LeetCode1716.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月15日 星期六 09时07分52秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int totalMoney(int n) {
    int k = n / 7;
    int r = n % 7;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += (i + 3) * 7;
    }
    ans += (2 * k + r + 1) * r / 2;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << totalMoney(n) << endl;
    return 0;
}
