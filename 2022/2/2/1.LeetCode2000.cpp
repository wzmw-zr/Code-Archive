/*************************************************************************
	> File Name: 1.LeetCode2000.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月02日 星期三 09时06分36秒
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

string reversePrefix(string word, char ch) {
    int ind = -1;
    for (int i = 0; word[i]; i++) {
        if (word[i] == ch) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        return word;
    }
    int l = 0, r = ind;
    while (l < r) {
        swap(word[l], word[r]);
        l++, r--;
    }
    return word;
}

int main() {
    return 0;
}
