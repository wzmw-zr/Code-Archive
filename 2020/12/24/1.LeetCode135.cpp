/*************************************************************************
	> File Name: 1.LeetCode135.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月24日 星期四 08时23分31秒
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

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n, 1), right(n, 1);
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) left[i] = left[i - 1] + 1;
        else left[i] = 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) right[i] = right[i + 1] + 1;
        else right[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += max(left[i], right[i]);
    return ans;
}

int main() {
    return 0;
}
