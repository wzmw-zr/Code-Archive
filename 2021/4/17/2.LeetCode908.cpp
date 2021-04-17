/*************************************************************************
	> File Name: 2.LeetCode908.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月17日 星期六 22时17分17秒
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

int smallestRangeI(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int n = A.size();
    int diff = A[n - 1] - A[0];
    if (diff <= 2 * K) return 0;
    return diff - 2 * K;
}

int main() {
    return 0;
}
