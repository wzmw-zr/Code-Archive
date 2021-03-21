/*************************************************************************
	> File Name: 2.LeetCode1799.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月21日 星期日 07时46分34秒
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

int getMaximumConsecutive(vector<int>& coins) {
    sort(coins.begin(), coins.end());
    int mmax = 0;
    for (int &x : coins) {
        if (mmax + 1 >= x) mmax += x;
        else break;
    }
    return mmax + 1;
}

int main() {
    return 0;
}
