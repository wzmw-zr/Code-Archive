/*************************************************************************
	> File Name: 1.LeetCode1518.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月17日 星期五 08时45分08秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int numWaterBottles(int numBottles, int numExchange) {
    int ans = numBottles;
    while (numBottles >= numExchange) {
        ans += numBottles / numExchange;
        numBottles = numBottles / numExchange + numBottles % numExchange;
    }
    return ans;
}

int main() {
    return 0;
}
