/*************************************************************************
	> File Name: 1.LeetCode1447.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月10日 星期四 00时06分33秒
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

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

vector<string> simplifiedFractions(int n) {
    unordered_set<string> st;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            int m = gcd(i, j);
            st.insert(to_string(j / m) + "/" + to_string(i / m));
        }
    }
    vector<string> ans(st.begin(), st.end());
    return ans;
}

int main() {
    return 0;
}
