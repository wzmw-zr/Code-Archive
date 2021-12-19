/*************************************************************************
	> File Name: 1.LeetCode5956.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月19日 星期日 10时30分34秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

string firstPalindrome(vector<string>& words) {
    for (auto s : words) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        if (s == temp) return s;
    }
    return "";
}

int main() {
    return 0;
}
