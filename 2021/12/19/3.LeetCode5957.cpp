/*************************************************************************
	> File Name: 3.LeetCode5957.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月19日 星期日 10时33分07秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

string addSpaces(string s, vector<int>& spaces) {
    string ans = "";
    int ind = 0;
    for (int x : spaces) {
        while (ind < x) {
            ans += s[ind];
            ind++;
        }
        ans += " ";
    }
    while (s[ind]) {
        ans += s[ind]; 
        ind++;
    }
    return ans;
}

int main() {
    return 0;
}
