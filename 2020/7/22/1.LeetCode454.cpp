/*************************************************************************
	> File Name: 1.LeetCode454.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月22日 星期三 18时21分37秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> mp;
    int cnt = 0;
    int len = A.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            mp[A[i] + B[j]]++;
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            int tmp = 0 - C[i] - D[j];
            if (mp.find((tmp)) != mp.end()) cnt += mp[tmp];
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n, 0), B(n, 0), C(n, 0), D(n, 0);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int i = 0; i < n; i++) cin >> C[i];
    for (int i = 0; i < n; i++) cin >> D[i];
    cout << fourSumCount(A, B, C, D) << endl;
    return 0;
}
