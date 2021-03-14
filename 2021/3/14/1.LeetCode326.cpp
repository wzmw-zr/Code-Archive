/*************************************************************************
	> File Name: 1.LeetCode326.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月14日 星期日 08时15分53秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    while (n != 1) {
        if (n % 3) return false;
        n /= 3;
    }
    return true;
}

int main() {
    return 0;
}
