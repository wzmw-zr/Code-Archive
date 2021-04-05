/*************************************************************************
	> File Name: 1.LeetCode80.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月06日 星期二 00时02分57秒
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

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n;
    int ind = 0, l = 0;
    while (l < n) {
        int i = 0;
        while (i + l < n && nums[i + l] == nums[l]) i++;
        if (i <= 2) {
            for (int j = 0; j < i; j++) nums[ind + j] = nums[l];
            ind += i;
        } else {
            nums[ind] = nums[l];
            nums[ind + 1] = nums[l];
            ind += 2;
        }
        l = i + l;
    }
    return ind;
}

int main() {
    return 0;
}
