/*************************************************************************
	> File Name: 4.LeetCode795.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月10日 星期三 09时53分13秒
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

int MaxLessEqualThanKSubarray(vector<int> &A, int K) {
    int n = A.size(), l = 0, r = 0, mmax = 0, cnt = 0;
    while (r < n) {
        mmax = max(mmax, A[r++]);
        if (mmax <= K) cnt += r - l;
        else {
            l = r;
            if (r < n) mmax = A[r];
        }
    }
    return cnt;
}

int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    return MaxLessEqualThanKSubarray(A, R) - MaxLessEqualThanKSubarray(A, L - 1);
}

int main() {
    return 0;
}
