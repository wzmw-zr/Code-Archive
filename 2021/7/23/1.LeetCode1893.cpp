/*************************************************************************
	> File Name: 1.LeetCode1893.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月23日 星期五 00时14分32秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    vector<int> check(51, 0);
    for (auto range : ranges) {
        for (int i = range[0]; i <= range[1]; i++) check[i] = 1;
    }
    for (int i = left; i <= right; i++) {
        if (!check[i]) return false;
    }
    return true;
}

int main() {
    return 0;
}
