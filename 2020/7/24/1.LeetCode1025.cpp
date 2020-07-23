/*************************************************************************
	> File Name: 1.LeetCode1025.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月24日 星期五 01时10分50秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

bool divisorGame(int N) {
    if (N <= 1) return false;
    for (int i = 1; i < N; i++) {
        if (N % i) continue;
        if (!divisorGame(N - i)) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    cout << (divisorGame(n) ? "true" : "false") << endl;
    return 0;
}
