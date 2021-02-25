/*************************************************************************
	> File Name: 1.LeetCode1178.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月26日 星期五 00时06分04秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

// TLE
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    int n = words.size(), m = puzzles.size();
    vector<int> words_state(n, 0), puzzles_state(m, 0), ans(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) words_state[i] |= (1 << (words[i][j] - 'a'));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; puzzles[i][j]; j++) puzzles_state[i] |= (1 << (puzzles[i][j] - 'a'));
        for (int j = 0; j < n; j++) {
            if ((words_state[j] & (1 << (puzzles[i][0] - 'a'))) && (puzzles_state[i] == (puzzles_state[i] | words_state[j]))) ans[i]++;
        }
    }
    return ans;
}

int main() {
    return 0;
}
