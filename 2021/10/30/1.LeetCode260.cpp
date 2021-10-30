/*************************************************************************
	> File Name: 1.LeetCode260.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月30日 星期六 08时04分01秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    unsigned int t = 0;
    for (int x : nums) t ^= x;
    unsigned int l = t & (-t);
    int x1 = 0, x2 = 0;
    for (int x : nums) {
        if (x & l) x1 ^= x;
        else x2 ^= x;
    }
    return {x1, x2};
}

int main() {
    return 0;
}
