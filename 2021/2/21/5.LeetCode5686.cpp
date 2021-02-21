/*************************************************************************
	> File Name: 5.LeetCode5686.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月21日 星期日 10时39分21秒
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

vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> left_cnt(n, 0), right_cnt(n, 0), left(n, 0), right(n, 0), ans(n, 0);
    for (int i = 1; i < n; i++) {
        left_cnt[i] = left_cnt[i - 1] + boxes[i - 1] - '0';
        left[i] = left[i - 1] + left_cnt[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        right_cnt[i] = right_cnt[i + 1] + boxes[i + 1] - '0';
        right[i] = right[i + 1] + right_cnt[i];
    }
    for (int i = 0; i < n; i++) ans[i] = left[i] + right[i];
    return ans;
}

int main() {
    return 0;
}
