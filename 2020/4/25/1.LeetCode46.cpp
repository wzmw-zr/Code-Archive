/*************************************************************************
	> File Name: 1.LeetCode46.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月25日 星期六 07时05分40秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void GetPermute(vector<vector<int>> &res, vector<int> &tmp, int *check, vector<int> &nums, int ind, int cnt) {
    if (ind == cnt) {
        res.push_back(tmp);
        return ;
    }
    for (int i = 0; i < cnt; i++) {
        if (check[i]) continue;
        tmp.push_back(nums[i]);
        check[i] = 1;
        GetPermute(res, tmp, check, nums, ind + 1, cnt);
        tmp.pop_back();
        check[i] = 0;
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    int cnt = nums.size();
    vector<vector<int>> res;
    vector<int> tmp;
    int check[cnt + 5];
    memset(check, 0, sizeof(check));
    GetPermute(res, tmp, check, nums, 0, cnt);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 1; i<= n; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    vector<vector<int>> res = permute(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
