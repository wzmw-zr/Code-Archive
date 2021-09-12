/*************************************************************************
	> File Name: 1.LeetCode678.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月12日 星期日 07时38分47秒
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

bool checkValidString(string s) {
    int diff = 0, star = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') diff++;
        else if (s[i] == ')') diff--;
        else star++;
        if (diff < 0) {
            if (star) diff++, star--;
            else return false;
        }
    }
    if (diff > star) return false;
    diff = star = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')') diff++;
        else if (s[i] == '(') diff--;
        else star++;
        if (diff < 0) {
            if (star) diff++, star--;
            else return false;
        }
    }
    return diff <= star;
}

int main() {
    return 0;
}
