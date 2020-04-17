/*************************************************************************
	> File Name: 1.LeetCode55.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月17日 星期五 10时24分19秒
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

bool Can_Jump(vector<int> &nums, int ind, int size) {
    if (ind >= size - 1) return true;
    int ret = false;
    for (int i = nums[ind]; !ret && i >= 1; i--) {
        ret |= Can_Jump(nums, ind + i, size);
    }
    return ret;
}

bool canJump(vector<int> &nums) {
    int len = nums.size();
    return Can_Jump(nums, 0, len);
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
