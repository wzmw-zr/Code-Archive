/*************************************************************************
	> File Name: 3.LeetCode396.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月28日 星期日 00时29分28秒
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

int maxRotateFunction(vector<int>& A) {
    long func_sum = 0, n = A.size(), sum = 0;
    for (int i = 0; i < n; i++) func_sum += A[i] * i, sum += A[i];
    long mmax = func_sum;
    for (int i = n - 1; i >= 0; i--) {
        func_sum -= A[i] * (n - 1);
        func_sum += sum - A[i];
        mmax = max(mmax, func_sum);
    }
    return mmax;
}

int main() {
    return 0;
}
