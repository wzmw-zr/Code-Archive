/*************************************************************************
	> File Name: 4.LeetCode995.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月11日 星期四 09时27分06秒
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


// TLE

void change(vector<int> &A, int &ind, int &K) {
    for (int i = ind, j = 0; j < K; j++) A[i + j] = !A[i + j];
}

int minKBitFlips(vector<int>& A, int K) {
    int n = A.size(), ind = 0, ans = 0;
    while (ind < n) {
        while (ind < n && A[ind]) ind++;
        if (n == ind) break;
        if (n - ind < K) return -1;
        change(A, ind, K);
        ans++;
    }
    return ans;
}

int main() {
    return 0;
}
