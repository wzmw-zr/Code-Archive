/*************************************************************************
	> File Name: 3.LeetCode5765.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月23日 星期日 11时04分30秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();
    if (s[n - 1] != '0') return false;
    vector<int> pre_sum(n + 1, 0);
    vector<int> check(n + 1, 0);
    check[1] = 1;
    pre_sum[1] = 1;
    for (int i = 1; i < n; i++) {
        pre_sum[i + 1] = pre_sum[i];
        if (s[i] == '1') continue;
        if (i < minJump) continue;
        int r = i - minJump;
        int l = max(0, i - maxJump);
        if (pre_sum[r + 1] - pre_sum[l] == 0) continue;
        check[i + 1] = true;
        pre_sum[i + 1]++;
    }
    return check[n];
} 

int main() {
    string s;
    int minJump, maxJump;
    cin >> s >> minJump >> maxJump;
    cout << (canReach(s, minJump, maxJump) ? "True" : "False") << endl;
    return 0;
}
