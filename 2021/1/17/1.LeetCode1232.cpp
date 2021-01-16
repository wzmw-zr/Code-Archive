/*************************************************************************
	> File Name: 1.LeetCode1232.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月17日 星期日 00时02分06秒
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

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n = coordinates.size();
    if (n == 2) return true;
    int x_1 = coordinates[0][0];
    int y_1 = coordinates[0][1];
    int x_2 = coordinates[1][0];
    int y_2 = coordinates[1][1];
    for (int i = 2; i < n; i++) {
        int x_3 = coordinates[i][0];
        int y_3 = coordinates[i][1];
        if (((y_2 - y_1) * (x_3 - x_2)) == ((y_3 - y_2) * (x_2 - x_1))) continue;
        return false;
    }
    return true;
}

int main() {
    return 0;
}
