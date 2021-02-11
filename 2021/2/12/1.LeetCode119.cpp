/*************************************************************************
	> File Name: 1.LeetCode119.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月12日 星期五 00时01分39秒
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

vector<int> getRow(int rowIndex) {
    vector<vector<int>> nums;
    nums.push_back(vector<int>(1, 1));
    nums.push_back(vector<int>(2, 1));
    for (int i = 2; i <= rowIndex; i++) {
        nums.push_back(vector<int>(i + 1, 1));
        for (int j = 1; j < i; j++) nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
    }
    return nums[rowIndex];
}

int main() {
    return 0;
}
