/*************************************************************************
	> File Name: 1.LeetCode1185.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月03日 星期一 09时48分36秒
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

vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int year_days(int year) {
    if (year % 100 == 0 && year % 400 == 0) return 366;
    if (year % 100 != 0 && year % 4 == 0) return 366;
    return 365;
}

int month_days(int month, int year) {
    if (month != 2) return months[month];
    if (year % 100 == 0 && year % 400 == 0) return months[month] + 1;
    if (year % 100 != 0 && year % 4 == 0) return months[month] + 1;
    return months[month];
}

string dayOfTheWeek(int day, int month, int year) {
    vector<string> day_to_string = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int days = 3;
    for (int i = 1971; i < year; i++) days += year_days(i);
    for (int i = 1; i < month; i++) days += month_days(i, year);
    days += day;
    days %= 7;
    return day_to_string[days];
}

int main() {
    int day, month, year;
    cin >> day >> month >> year;
    cout << dayOfTheWeek(day, month, year) << endl;
    return 0;
}
