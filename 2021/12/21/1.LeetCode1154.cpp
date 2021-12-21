/*************************************************************************
	> File Name: 1.LeetCode1154.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月21日 星期二 08时59分15秒
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

int dayOfYear(string date) {
    vector<int> days({0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    if ((!(year % 100) && !(year % 400)) || ((year % 100) && !(year % 4))) days[2]++;
    int ans = 0;
    for (int i = 1; i < month; i++) ans += days[i];
    ans += day;
    return ans;
}

int main() {
    string date;
    cin >> date;
    cout << dayOfYear(date) << endl;
    return 0;
}
