/*************************************************************************
	> File Name: 3.LeetCode338.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月03日 星期三 00时41分20秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> countBits(int num) {
    vector<int> ans(num + 1, 0);
    int highest = 1;
    for (int i = 1; i <= num; i++) {
        if (i & (i - 1) == 0) highest = i;
        ans[i] = ans[i - highest] + 1;
    }
    return ans;
}

int main() {
    return 0;
}
