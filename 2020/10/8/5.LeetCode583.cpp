/*************************************************************************
	> File Name: 5.LeetCode583.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月08日 星期四 14时40分22秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int minDistance(string word1, string word2) {
    int len_1 = word1.size(), len_2 = word2.size(), same_len = 0;
    cout << len_1 << " " << len_2 << endl;
    vector<vector<int>> dp(len_1 + 5, vector<int>(len_2 + 5, 0));
    for (int i = 1; i <= len_1; i++) {
        for (int j = 1; j <= len_2; j++) {
            dp[i][j] = (word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] + 1  : max(dp[i][j - 1], dp[i - 1][j]));
            same_len = max(same_len, dp[i][j]);
        }
    }
    cout << "sam_len : " << same_len << endl; 
    return len_1 + len_2 - 2 * same_len;
}

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    cout << word1 << endl << word2 << endl;
    cout << minDistance(word1, word2) << endl;
    return 0;
}
