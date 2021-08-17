/*************************************************************************
	> File Name: 1.LeetCode551.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月17日 星期二 11时08分23秒
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

bool checkRecord(string s) {
    int a = 0, l = 0;
    for (char c : s) {
        if (c == 'A') a++, l = 0;
        else if (c == 'L') l++;
        else l = 0;
        if (a >= 2 || l >= 3) return false;
    }
    return true;
}

int main() {
    return 0;
}
