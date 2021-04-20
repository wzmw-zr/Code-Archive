/*************************************************************************
	> File Name: 3.LeetCode848.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月20日 星期二 21时42分08秒
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

string shiftingLetters(string S, vector<int>& shifts) {
    int n = shifts.size();
    int dis = 0;
    for (int i = n - 1; i >= 0; i--) {
        dis += shifts[i];
        dis %= 26;
        int temp = (dis + S[i] - 'a') % 26 + 'a';
        S[i] = (char) temp;
    }
    return S;
}

int main() {
    return 0;
}
