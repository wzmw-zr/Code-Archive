/*************************************************************************
	> File Name: 4.LeetCode60.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月16日 星期二 17时44分07秒
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

void dfs(vector<string> &permutation, vector<int> &check, string &path, int ind, int &n) {
    if (ind == n) {
        permutation.push_back(path);
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (check[i]) continue;
        check[i] = 1;
        path[ind] = i + '0';
        dfs(permutation, check, path, ind + 1, n);
        check[i] = 0;
    }
}

string getPermutation(int n, int k) {
    string path(n, ' ');
    vector<string> permutation;
    vector<int> check(n + 1, 0);
    dfs(permutation, check, path, 0, n);
    return permutation[k - 1];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << getPermutation(n, k) << endl;
    return 0;
}
