/*************************************************************************
	> File Name: 1.LeetCode896.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月28日 星期日 00时03分33秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isMonotonic(vector<int>& A) {
    int n = A.size(), flag = -1;
    for (int i = 0; i < n - 1; i++) {
        if (A[i] == A[i + 1]) continue;
        if (A[i] < A[i + 1]) {
            if (flag == 1) return false;
            flag = 0;
        } else {
            if (flag == 0) return false;
            flag = 1;
        }
    }
    return true;
}

int main() {
    return 0;
}
