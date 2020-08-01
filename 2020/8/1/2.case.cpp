/*************************************************************************
	> File Name: 2.case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月01日 星期六 08时01分36秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void handle(vector<int> &nums) {
    if (nums.size() == 0) return ;
    int tmp = nums[0];
    for (auto iter = nums.begin() + 1; iter != nums.end(); ) {
        if (tmp == *iter) {
            nums.erase(iter);
            continue;
        }
        tmp = *iter;
        iter++;
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];
    handle(nums);
    for (auto &x : nums) cout << x << " ";
    cout << endl;
    return 0;
}
