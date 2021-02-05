/*************************************************************************
	> File Name: 4.LeetCode1104.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月05日 星期五 22时56分12秒
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

int longestOnes(vector<int>& A, int K) {
    int ans = K;
    int l = 0, r = 0, n = A.size();
    int cnt = 0;
    while (r < n) {
        cnt += A[r++] == 1 ? 0 : 1;
        while (cnt > K) cnt -= A[l++] == 1 ? 0 : 1;
        ans = max(ans, r - l);
    }
    return ans;
}

int main() {
    return 0;
}
