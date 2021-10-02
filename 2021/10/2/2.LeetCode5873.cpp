/*************************************************************************
	> File Name: 2.LeetCode5873.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月02日 星期六 22时38分17秒
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

int maxConsecutiveAnswers(string answerKey, int k) {
    int n = answerKey.size();
    int l = 0, r = 0;
    int ans = 0;
    int x = 0;
    while ((l < n) && (r < n)) {
        if (answerKey[r] == 'F') x++;
        if (x == k + 1) ans = max(ans, r - l);
        while (l < r && x == k + 1) {
            if (answerKey[l] == 'F') x--;
            l++;
        }
        r++;
    }
    ans = max(ans, r - l);
    x = 0;
    l = r = 0;
    while ((l < n) && (r < n)) {
        if (answerKey[r] == 'T') x++;
        if (x == k + 1) ans = max(ans, r - l);
        while (l < r && x == k + 1) {
            if (answerKey[l] == 'T') x--;
            l++;
        }
        r++;
    }
    ans = max(ans, r - l);
    return ans;
}

int main() {
    string answerKey;
    int k;
    cin >> answerKey >> k;
    cout << maxConsecutiveAnswers(answerKey, k) << endl;
    return 0;
}
