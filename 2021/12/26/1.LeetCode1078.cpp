/*************************************************************************
	> File Name: 1.LeetCode1078.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月26日 星期日 09时41分55秒
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

vector<string> split(string &text) {
    vector<string> ans;
    int ind = 0;
    while (text[ind]) {
        while (text[ind] && text[ind] == ' ') ind++;
        if (!text[ind]) continue;
        string temp = "";
        while (text[ind] && text[ind] != ' ') temp += text[ind++];
        ans.push_back(temp);
    }
    return ans;
}

vector<string> findOcurrences(string text, string first, string second) {
    vector<string> words = split(text);
    int n = words.size();
    vector<string> ans;
    for (int i = 0; i <= n - 3; i++) {
        if (words[i] == first && words[i + 1] == second) ans.push_back(words[i + 2]);
    }
    return ans;
}

int main() {
    return 0;
}
