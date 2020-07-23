/*************************************************************************
	> File Name: 2.LeetCode1025.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月24日 星期五 01时25分35秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

bool divisorGame(int N) {
    vector<int> dp(N + 5, 0);
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (i % j) continue;
            dp[i] |= !dp[i - j];
        }
    }
    return dp[N];
}

int main() {
    int n;
    cin >> n;
    cout << (divisorGame(n) ? "true" : "false") << endl;
    return 0;
}
