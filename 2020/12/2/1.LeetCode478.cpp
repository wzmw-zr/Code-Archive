/*************************************************************************
	> File Name: 1.LeetCode478.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月02日 星期三 14时54分45秒
 ************************************************************************/

#include<iostream>
#include<ctime>
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

class Solution {
public:
    double radius, x_center, y_center;
    Solution(double radius, double x_center, double y_center) : radius(radius), x_center(x_center), y_center(y_center){
        srand(time(0));
    }

    vector<double> randPoint() {
        int flag_1 = rand() % 2, flag_2 = rand() % 2;
        double div_1 = rand() % 100000, div_2 = rand() % 100000;
        double x = (flag_1 ? 1 : -1) * div_1 / 100000 * radius + x_center;
        double y = (flag_2 ? 1 : -1) * div_2 / 100000 * radius + y_center;
        return {x, y};
    }
};

int main() {
    return 0;
}
