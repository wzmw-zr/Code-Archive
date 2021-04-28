/*************************************************************************
	> File Name: 3.LeetCode862.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月29日 星期四 01时04分54秒
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


// WA
int shortestSubarray(vector<int>& A, int K) {
    long sum = 0;
    int l = 0, r = 0, n = A.size();
    int ans = INT32_MAX;
    while (r < n) {
        sum += (long) A[r];
        while (sum >= K) {
            ans = min(ans, r - l + 1);
            sum -= (long) A[l++];
        }
        r++;
    }
    while (sum >= K) {
        ans = min(ans, r - l + 1);
        sum -= (long) A[l++];
    }
    return ans == INT32_MAX ? -1 : ans;
}

int main() {
    return 0;
}
