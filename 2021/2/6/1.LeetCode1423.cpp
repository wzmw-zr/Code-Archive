/*************************************************************************
	> File Name: 1.LeetCode1423.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月06日 星期六 00时01分30秒
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

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size(), len = n - k;
    int sum = 0, res = INT32_MAX, temp = 0;
    int l = 0, r = 0;
    while (r < n) {
        temp += cardPoints[r];
        sum += cardPoints[r];
        if (r - l + 1 == len) {
            res = min(res, temp);
            temp -= cardPoints[l++];
        }
        r++;
    }
    return res == INT32_MAX ? sum : sum - res;
}

int main() {
    return 0;
}
