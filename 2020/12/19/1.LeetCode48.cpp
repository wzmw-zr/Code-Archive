/*************************************************************************
	> File Name: 1.LeetCode48.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月19日 星期六 08时22分52秒
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

void rotate(vector<vector<int>>& matrix) {
    auto temp = matrix;
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n - i - 1] = matrix[i][j];
        }
    }
    matrix = temp;
}

int main() {
    return 0;
}
