/*************************************************************************
	> File Name: 1.LeetCode1011.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月26日 星期一 00时09分03秒
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

bool check(vector<int> &weights, int mmax, int &D) {
    int ind = 0, sum = 0, cnt = 0, n = weights.size();
    for (int i = 0; i < n; i++) {
        if (weights[i] > mmax) return false;
        if (sum + weights[i] <= mmax) sum += weights[i];
        else {
            cnt++;
            sum = weights[i];
        }
    }
    cnt++;
    if (cnt <= D) return true;
    return false;
}

int shipWithinDays(vector<int>& weights, int D) {
    int sum = 0;
    for (int x :weights) sum += x;
    int l = 0, r = sum;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(weights, mid, D)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    return 0;
}
