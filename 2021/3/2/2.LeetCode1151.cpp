/*************************************************************************
	> File Name: 2.LeetCode1151.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月02日 星期二 00时18分23秒
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

int minSwaps(vector<int>& data) {
    int len = 0;
    for (int &x : data) len += x;
    int n = data.size(), l = 0, r = 0, ans = INT32_MAX, cnt = 0;
    while (r < len - 1) cnt += data[r++];
    while (r < n) {
        cnt += data[r++];
        ans = min(ans, len - cnt);
        cnt -= data[l++];
    }
    return ans;
}

int main() {
    return 0;
}
