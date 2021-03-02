/*************************************************************************
	> File Name: 1.LeetCode338.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月03日 星期三 00时01分44秒
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

vector<int> countBits(int num) {
    vector<int> ans(num + 1, 0);
    for (int i = 0; i <= num; i++) ans[i] = __builtin_popcount(i);
    return ans;
}

int main() {
    int n;
    cin >> n;
    auto ans = countBits(n);
    for (int i = 0; i <= n; i++) cout << i << " " << ans[i] << endl;
    return 0;
}
