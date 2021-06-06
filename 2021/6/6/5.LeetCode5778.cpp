/*************************************************************************
	> File Name: 5.LeetCode5778.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月06日 星期日 11时51分00秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int minFlips(string s) {
    int n = s.size();
    int odd = (n - 1) & 1;
    vector<int> one(2, 0), zero(2, 0);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '0') {
            zero[i & 1]++;
        } else {
            one[i & 1]++;
        }
    }
    int ans = INT32_MAX;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '0') {
            swap(one[0], one[1]);
            if (odd) swap(zero[0], zero[1]);
            else {
                zero[0]--, zero[1]++;
                swap(zero[0], zero[1]);
            }
            ans = min(ans, one[0] + zero[1]);
            ans = min(ans, one[1] + zero[0]);
        } else {
            swap(zero[0], zero[1]);
            if (odd) swap(one[0], one[1]);
            else {
                one[0]--, one[1]++;
                swap(one[0], one[1]);
            }
            ans = min(ans, one[0] + zero[1]);
            ans = min(ans, one[1] + zero[0]);
        }
    }
    return ans;
}

int main() {
    return 0;
}
