/*************************************************************************
	> File Name: 2.LeetCode5946.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月25日 星期六 22时30分38秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int count_word(string &s) {
    int cnt = 0;
    int ind = 0;
    while (s[ind]) {
        while (s[ind] && s[ind] == ' ') ind++;
        if (s[ind]) cnt++;
        while (s[ind] && s[ind] != ' ') ind++;
    }
    return cnt;
}

int mostWordsFound(vector<string>& sentences) {
    int ans = 0;
    for (auto sentence : sentences) ans = max(ans, count_word(sentence));
    return ans;
}

int main() {
    return 0;
}
