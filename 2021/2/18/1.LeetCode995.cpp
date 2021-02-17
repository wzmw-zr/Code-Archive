/*************************************************************************
	> File Name: 1.LeetCode995.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月18日 星期四 00时01分55秒
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


int minKBitFlips(vector<int>& A, int K) {
    int n = A.size(), cnt = 0;
    vector<int> pre(n + 2, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = (pre[i + 1] + pre[i]) % 2;
        if ((pre[i + 1] + A[i]) % 2) continue;
        if (i + K > n) return -1;
        pre[i + 1]++, pre[i + K + 1]--, cnt++;
    }
    return cnt;
}

# if 0
int minKBitFlips(vector<int>& A, int K) {
    int n = A.size(), cnt = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 1) continue;
        if (i + K > n) return -1;
        for (int j = 0; j < K; j++) A[i + j] = !A[i + j];
        cnt++;
    }
    return cnt;
}
# endif

int main() {
    return 0;
}
