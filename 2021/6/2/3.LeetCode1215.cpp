/*************************************************************************
	> File Name: 3.LeetCode1215.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月02日 星期三 00时33分42秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

long cal_pow(int p) {
    long ans = 1;
    for (int i = 0; i < p; i++) ans *= 10;
    return ans;
}

void dfs(int p, long num, long sum, unordered_set<int> &ans, long &low, long &high) {
    if (p == 10) return ;
    sum += cal_pow(p) * num;
    if (sum > high) return ;
    if ((sum >= low) && (sum <= high)) ans.insert(sum);
    if (num == 0) {
        dfs(p + 1, num + 1, sum, ans, low, high);
    } else if (num == 9) {
        dfs(p + 1, num - 1, sum, ans, low, high);
    } else {
        dfs(p + 1, num + 1, sum, ans, low, high);
        dfs(p + 1, num - 1, sum, ans, low, high);
    }
}

vector<int> countSteppingNumbers(int low, int high) {
    long l = low, h = high;
    unordered_set<int> ans;
    for (long i = 0; i <= 9; i++) dfs(0, i, (long) 0, ans, l, h);
    vector<int> res;
    for (int x : ans) res.push_back(x);
    sort(res.begin(), res.end());
    return res;
}

int main() {
    return 0;
}
