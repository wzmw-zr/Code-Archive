/*************************************************************************
	> File Name: 2.LeetCode5823.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月25日 星期日 10时31分23秒
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

int getLucky(string s, int k) {
    vector<int> nums;
    for (char c : s) {
        int x = (c - 'a') + 1;
        while (x) {
            nums.push_back(x % 10);
            x /= 10;
        }
    }
    int num = 0;
    for (int x : nums) num += x;
    for (int i = 1; i < k; i++) {
        int t = 0;
        while (num) {
            t += num % 10;
            num /= 10;
        }
        num = t;
    }
    return num;
}

int main() {
    return 0;
}
