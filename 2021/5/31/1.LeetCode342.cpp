/*************************************************************************
	> File Name: 1.LeetCode342.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月31日 星期一 00时01分45秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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

bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    if (__builtin_popcount(n) > 1) return false;
    if (__builtin_ctz(n) & 1) return false;
    return true;
}

int main() {
    return 0;
}
