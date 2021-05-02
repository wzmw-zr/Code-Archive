/*************************************************************************
	> File Name: 2.LeetCode5749.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月03日 星期一 01时16分08秒
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

int getMinSwaps(string num, int k) {
    string num_k = num;
    int n = num.size();
    for (int i = 0; i < k; i++) 
        next_permutation(num_k.begin(), num_k.end());
    vector<int> mp[10];
    vector<int> idx(10, 0);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
        mp[num[i] - '0'].push_back(i);
    for (int i = 0; i < n; i++) 
        arr[i] = mp[num_k[i] - '0'][idx[num_k[i] - '0']++];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) ans++;
        }
    }
    return ans;
}

int main() {
    return 0;
}
