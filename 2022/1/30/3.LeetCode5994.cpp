/*************************************************************************
	> File Name: 3.LeetCode5994.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月30日 星期日 10时49分23秒
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

long q_pow(int power, int k, int modulo) {
    long base = power;
    long ans = 1;
    while (k) {
        if (k & 1) {
            ans = (ans * base) % modulo;
        }
        base = (base * base) % modulo;
        k >>= 1;
    }
    return ans;
}

int val(char c) {
    return static_cast<int>(c - 'a') + 1;
}

string subStrHash(string s, int power, int modulo, int k, int hashValue) {
    int n = s.size();
    long base = 1;
    long value = 0;
    for (int i = n - k; i < n; i++) {
        value = (value + (base * val(s[i])) % modulo) % modulo;
        base = (base * power) % modulo;
    }
    int ind = 0;
    for (int i = n - k - 1; i >= 0; i--) {
        if (value == hashValue) {
            ind = i + 1;
        }
        value = ((value * power) % modulo - (base * val(s[i + k])) % modulo + val(s[i])) % modulo;
        if (value < 0) {
            value += modulo;
        }
    }
    if (value == hashValue) {
        ind = 0;
    }
    return s.substr(ind, k);
}

int main() {
    return 0;
}
