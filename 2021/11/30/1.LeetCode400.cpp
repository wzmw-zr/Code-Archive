/*************************************************************************
	> File Name: 1.LeetCode400.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月30日 星期二 08时34分27秒
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
#include <cmath>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int findNthDigit(int n) {
    long t = n, d = 1;
    int num = 0;
    while (t > d * pow(10, d - 1) * 9) {
        num += 9 * pow(10, d - 1);
        t -= 9 * d * pow(10, d - 1);
        d++;
    }
    num += t / d;
    int r = t % d;
    if (!r) return num % 10;
    return to_string(num + 1)[r - 1] -= '0';
}

int main() {
    int n;
    cin >> n;
    cout << findNthDigit(n) << endl;
    return 0;
}
