/*************************************************************************
	> File Name: 1.LeetCode519.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月27日 星期六 08时12分30秒
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

class Solution {
public:
    int n_rows;
    int n_cols;
    set<int> st;

    Solution(int n_rows, int n_cols) : n_rows(n_rows), n_cols(n_cols) {
        srand(time(0));
    }

    vector<int> flip() {
        int x, y;
        while (1) {
            int t = rand() % (n_rows * n_cols);
            if (st.count(t)) continue;
            x = t / n_cols, y = t % n_cols;
            st.insert(t);
            break;
        }
        return {x, y};
    }

    void reset() {
        st.clear();
    }
};

int main() {
    return 0;
}
