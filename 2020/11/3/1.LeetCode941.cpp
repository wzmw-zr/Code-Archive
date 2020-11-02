/*************************************************************************
	> File Name: 1.LeetCode941.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月03日 星期二 00时05分56秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

bool validMountainArray(vector<int>& A) {
    if (A.size() < 3) return false;
    int mid = 0, num = A[0], n = A.size();
    for (int i = 1; i < n; i++) {
        if (A[i] == num) return false;
        if (A[i] > num) {
            num = A[i];
            mid = i;
            continue;
        }
        break;
    }
    if (mid == 0 || mid == (n - 1)) return false;
    for (int i = mid + 1; i < n; i++) {
        if (A[i] >= num) return false;
        num = A[i];
    }
    return true;
}

int main() {
    vector<int> A;
    int n;
    while (cin >> n) A.push_back(n);
    cout << (validMountainArray(A) ? "True" : "False") << endl;
    return 0;
}
