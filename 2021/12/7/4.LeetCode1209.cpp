/*************************************************************************
	> File Name: 4.LeetCode1209.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月07日 星期二 10时32分13秒
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

// TLE

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

string removeDuplicates(string s, int k) {
    string ans = "";
    for (char c : s) {
        ans.push_back(c);
        while (ans.size() >= k) {
            int n = ans.size();
            int flag = 0;
            for (int i = n - 1; i >= n - k; i--) {
                if (ans[i] == ans[n - 1]) continue;
                flag = 1;
                break;
            }
            if (flag) break;
            for (int i = 0; i < k; i++) ans.pop_back();
        }
    }
    return ans;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << removeDuplicates(s, k) << endl;
    return 0;
}
