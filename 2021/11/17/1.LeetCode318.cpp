/*************************************************************************
	> File Name: 1.LeetCode318.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月17日 星期三 08时21分55秒
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

int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<int> states(n, 0);
    for (int i = 0; i < n; i++) {
        for (char c : words[i]) states[i] |= 1 << (c - 'a');
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (states[i] & states[j]) continue;
            ans = max(ans, int(words[i].size() * words[j].size()));
        }
    }
    return ans;
}

int main() {
    return 0;
}
