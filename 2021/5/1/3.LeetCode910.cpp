/*************************************************************************
	> File Name: 3.LeetCode910.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月01日 星期六 00时49分21秒
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
int bs_first_ge(vector<int> &A, int num) {
    int n = A.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (A[mid] >= num) r = mid;
        else l = mid + 1;
    }
    return l;
}

int bs_last_le(vector<int> &A, int num) {
    int n = A.size();
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (A[mid] <= num) l = mid;
        else r = mid - 1;
    }
    return l;
}

int smallestRangeII(vector<int>& A, int K) {
    int n = A.size();
    sort(A.begin(), A.end());
    int ans = INT32_MAX;
    for (int i = 0; i < n; i++) {
        int ind_1 = bs_first_ge(A, A[i] + 2 * K);
        int ind_2 = bs_last_le(A, A[i] + 2 * K);
        if (ind_1 != i) ans = min(ans, abs(A[i] + 2 * K - A[ind_1]));
        if (ind_2 != i) ans = min(ans, abs(A[i] + 2 * K - A[ind_2]));
    }
    return ans == INT32_MAX ? 0 : ans;
}

int main() {
    return 0;
}
