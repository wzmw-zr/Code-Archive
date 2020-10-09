/*************************************************************************
	> File Name: 6.LeetCode72.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月09日 星期五 20时57分50秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int minDistance(string word1, string word2) {
    int len_1 = word1.size(), len_2 = word2.size();
    vector<vector<int>> dp(len_1 + 5, vector<int>(len_2 + 5, 0));
    for (int i = 1; i <= len_2; i++) dp[0][i] = i;
    for (int i = 1; i <= len_1; i++) dp[i][0] = i;
    for (int i = 1; i <= len_1; i++) {
        for (int j = 1; j <= len_2; j++) {
            if (word1[i - 1] == word2[j - 1]) dp[i][j] = min(dp[i - 1][j - 1] - 1, min(dp[i - 1][j], dp[i][j - 1])) + 1;
            else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    return dp[len_1][len_2];
}

int main() {
    string word1 = "", word2 = "";
    cout << minDistance(word1, word2) << endl;
    return 0;
}
