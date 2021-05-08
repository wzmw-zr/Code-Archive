/*************************************************************************
	> File Name: 3.LeetCode246.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月08日 星期六 14时02分35秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;


void init(unordered_map<char, char> &match) {
    match['0'] = '0';
    match['1'] = '1';
    match['2'] = 0;
    match['3'] = 0;
    match['4'] = 0;
    match['5'] = 0;
    match['6'] = '9';
    match['7'] = 0;
    match['8'] = '8';
    match['9'] = '6';
}

bool isStrobogrammatic(string num) {
    unordered_map<char, char> match;
    init(match);
    int l = 0, r = (int) num.size() - 1;
    while (l <= r) {
        if (!match[num[l]] || !match[num[r]]) 
            return false;
        if (num[l] != match[num[r]]) 
            return false;
        l++, r--;
    }
    return true;
}


int main() {
    return 0;
}
