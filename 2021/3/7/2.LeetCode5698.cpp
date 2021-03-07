/*************************************************************************
	> File Name: 2.LeetCode5698.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月07日 星期日 10时36分44秒
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
#include<cmath>
using namespace std;

int minElements(vector<int>& nums, int limit, int goal) {
    long sum = 0;
    for (int &x : nums) sum += x;
    long dis = abs(sum - goal);
    return dis / limit + (dis % limit == 0 ? 0 : 1);
}

int main() {
    return 0;
}
