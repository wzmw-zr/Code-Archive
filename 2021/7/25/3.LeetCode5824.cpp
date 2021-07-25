/*************************************************************************
	> File Name: 3.LeetCode5824.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月25日 星期日 10时43分15秒
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

string maximumNumber(string num, vector<int>& change) {
    for (int i = 0; num[i]; i++) {
        int x = num[i] - '0';
        if (change[x] <= x) continue;
        while (num[i] && (change[x] >= x)) {
            num[i] = '0' + change[x];
            x = num[++i] - '0';
        }
        break;
    }
    return num;
}

int main() {
    return 0;
}
