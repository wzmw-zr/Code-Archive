/*************************************************************************
	> File Name: 2.LeetCode55.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月17日 星期五 11时08分07秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

bool canJump(vector<int> &nums) {
    int len = nums.size();
    int max_ind = 0;
    for (int i = 0; i <= len && i <= len - 1; i++) {
        max_ind = max(max_ind, i + nums[i]); 
    }
    if (max_ind >= len - 1) return true;
    return false;
}

int main() {
    vector<int> data;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }
    printf("%s\n", canJump(data) ? "Yes" : "No");
    return 0;
}
