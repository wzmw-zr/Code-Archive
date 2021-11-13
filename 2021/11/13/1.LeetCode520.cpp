/*************************************************************************
	> File Name: 1.LeetCode520.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月13日 星期六 07时49分44秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

bool detectCapitalUse(string word) {
    if (word[0] >= 'a' && word[0] <= 'z') {
        for (char c : word) {
            if (c >= 'a' && c <= 'z') continue;
            return false;
        }
        return true;
    }
    int flag = 0;
    for (int i = 1; word[i]; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') continue;
        flag = 1;
        break;
    }
    if (!flag) return true;
    for (int i = 1; word[i]; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') continue;
        return false;
    }
    return true;
}

int main() {
    return 0;
}
