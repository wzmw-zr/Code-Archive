/*************************************************************************
	> File Name: 2.LeetCode6001.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月06日 星期日 10时40分36秒
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

long long smallestNumber(long long num) {
    vector<int> digits;
    int zero_cnt = 0;
    long long ans = 0;
    if (num >= 0) {
        do {
            if (num % 10) {
                digits.push_back(num % 10);
            } else {
                zero_cnt++;
            }
            num /= 10;
        } while (num);
        sort(digits.begin(), digits.end());
        if (digits.size()) {
            ans = digits[0];
            for (int i = 0; i < zero_cnt; i++) {
                ans *= 10;
            }
            for (int i = 1; i < digits.size(); i++) {
                ans = ans * 10 + digits[i];
            }
        }
    } else {
        num *= -1;
        while (num) {
            if (num % 10) {
                digits.push_back(num % 10);
            } else {
                zero_cnt++;
            }
            num /= 10;
        }
        sort(digits.begin(), digits.end(), greater<int>());
        ans = digits[0];
        for (int i = 1; i < digits.size(); i++) {
            ans = ans * 10 + digits[i];
        }
        for (int i = 0; i < zero_cnt; i++) {
            ans *= 10;
        }
        ans *= -1;
    }
    return ans;
}

int main() {
    long long num;
    cin >> num;
    cout << smallestNumber(num) << endl;
    return 0;
}
