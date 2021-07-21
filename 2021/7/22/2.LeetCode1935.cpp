/*************************************************************************
	> File Name: 2.LeetCode1935.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月22日 星期四 00时25分33秒
 ************************************************************************/

#include <iostream>
#include <sstream>
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

int canBeTypedWords(string text, string brokenLetters) {
    vector<int> check(26, 0);
    for (char c : brokenLetters) check[c - 'a'] = 1;
    string str;
    stringstream sstrm(text);
    int ans = 0;
    while (sstrm >> str) {
        int flag = 0;
        for (char c : str) {
            if (!check[c - 'a']) continue;
            flag = 1;
            break;
        }
        if (flag) continue;
        ans++;
    }
    return ans;
}

int main() {
    return 0;
}
