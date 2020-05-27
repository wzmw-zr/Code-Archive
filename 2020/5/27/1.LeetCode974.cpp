/*************************************************************************
	> File Name: 1.LeetCode974.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月27日 星期三 07时05分35秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraysDivByK(vector<int>& A, int K) {
    vector<int> pre_sum(A.size() + 5, 0);
    unordered_map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        pre_sum[i + 1] = ((pre_sum[i] + A[i]) % K + K) % K;
    }
    for (int i = 0; i <= A.size(); i++) {
        cnt += mp[pre_sum[i]];
        mp[pre_sum[i]]++;
    }
    return cnt;
}

int main() {
    int n, k, m;
    cin >> n >> k;
    vector<int> num;
    for (int i = 0; i < n; i++) {
        cin >> m;
        num.push_back(m);
    }
    cout << subarraysDivByK(num, k) << endl;
    return 0;
}
