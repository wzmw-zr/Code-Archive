/*************************************************************************
	> File Name: 2.LeetCode338.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月03日 星期三 00时05分52秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int get_one_cnt(int x) {
    int cnt = 0;
    while (x) {
        if (x & 1) cnt++;
        x >>= 1;
    }
    return cnt;
}

vector<int> countBits(int num) {
    vector<int> ans(num + 1, 0);
    for (int i = 0; i <= num; i++) ans[i] = get_one_cnt(i);
    return ans;
}

int main() {
    return 0;
}
