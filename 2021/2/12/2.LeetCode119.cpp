/*************************************************************************
	> File Name: 2.LeetCode119.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月12日 星期五 00时10分17秒
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
    vector<vector<int>> nums(2, vector<int>(rowIndex + 1, 1));
    for (int i = 2; i <= rowIndex; i++) {
        int ind = i & 1;
        int pre = !ind;
        for (int j = 1; j < i; j++) nums[ind][j] = nums[pre][j - 1] + nums[pre][j];
    }
    return nums[rowIndex & 1];
}

int main() {
    return 0;
}
