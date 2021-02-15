/*************************************************************************
	> File Name: 4.LeetCode1759.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月15日 星期一 13时29分36秒
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

int countHomogenous(string s) {
    int l = 0, r = 0, ans = 0;
    while (s[r]) {
        while (s[r] && s[r] == s[l]) r++;
        long temp = r - l;
        temp = temp * (temp + 1) / 2;
        temp %= 1000000007;
        ans += temp;
        ans %= 1000000007;
        l = r;
    }
    return ans;
}

int main() {
    return 0;
}
