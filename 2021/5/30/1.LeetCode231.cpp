/*************************************************************************
	> File Name: 1.LeetCode231.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月30日 星期日 00时02分00秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n >= 0) return __builtin_popcount(n) == 1;
    return false;
}

int main() {
    return 0;
}
