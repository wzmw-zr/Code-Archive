/*************************************************************************
	> File Name: 2.LeetCode66.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月17日 星期三 14时29分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    reverse(digits.begin(), digits.end());
    digits[0]++;
    for (int i = 0; i < digits.size(); i++) {
        if (digits[i] < 10) break;
        digits[i] -= 10;
        if (i + 1 == digits.size()) digits.push_back(0);
        digits[i + 1]++;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

int main() {
    return 0;
}
