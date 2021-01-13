/*************************************************************************
	> File Name: 1.LeetCode1018.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月14日 星期四 00时04分28秒
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

vector<bool> prefixesDivBy5(vector<int>& A) {
    int n = A.size(), res = 0;
    vector<bool> ans(n, false);
    for (int i = 0; i < n; i++) {
        res = res * 2 + A[i];
        if ((res % 5) == 0) ans[i] = true;
        res %= 5;
    }
    return ans;
}

int main() {
    return 0;
}
