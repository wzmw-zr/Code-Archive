/*************************************************************************
	> File Name: 6.LeetCode1955.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月15日 星期一 20时25分43秒
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

void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    if (n <= 1) return ;
    for (int i = 0; i + 1 < n; i += 2) swap(nums[i], nums[i + 1]);
    return ;
}

int main() {
    return 0;
}
