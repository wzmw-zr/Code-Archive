/*************************************************************************
	> File Name: 1.LeetCode1442.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月18日 星期二 00时02分49秒
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

int countTriplets(vector<int>& arr) {
    int n = arr.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) 
        pre[i + 1] = pre[i] ^ arr[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int t1 = pre[j] ^ pre[i];
            for (int k = j; k < n; k++) {
                int t2 = pre[k + 1] ^ pre[j];
                if (t1 == t2) ans++;
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
