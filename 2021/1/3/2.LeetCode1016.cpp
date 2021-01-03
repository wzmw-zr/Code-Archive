/*************************************************************************
	> File Name: 2.LeetCode1016.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月03日 星期日 08时51分44秒
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

bool queryString(string S, int N) {
    unordered_set<int> nums;
    for (int i = 0; S[i]; i++) {
        int num = 0;
        for (int j = 1; j <= 30 && S[i + j - 1]; j++) { 
            num <<= 1;
            num |= S[i + j - 1] - '0';
            if (num && num <= N) nums.insert(num);
        }
    }
    return nums.size() == N;
}

int main() {
    string S;
    int N;
    cin >> S >> N;
    cout << (queryString(S, N) ? "Yes" : "No") << endl;
    return 0;
}
