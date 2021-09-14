/*************************************************************************
	> File Name: 1.LeetCode524.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月14日 星期二 08时09分22秒
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

bool check(string &s, string &d) {
    int ind_1 = 0, ind_2 = 0;
    while (s[ind_1] && d[ind_2]) {
        if (s[ind_1] == d[ind_2]) ind_2++;
        ind_1++;
    }
    return !d[ind_2];
}

string findLongestWord(string s, vector<string>& dictionary) {
    string ans = "";
    for (auto &&d : dictionary) {
        if (check(s, d)) {
            if (ans.size() > d.size()) continue;
            else if (ans.size() < d.size()) ans = d;
            else ans = min(ans, d);
        }
    }
    return ans;
}

int main() {
    return 0;
}
