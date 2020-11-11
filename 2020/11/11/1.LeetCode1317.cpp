/*************************************************************************
	> File Name: 1.LeetCode1317.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月11日 星期三 08时24分19秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

bool check(int x, int y) {
    while (x) {
        if (x % 10) x /= 10;
        else return false;
    }
    while (y) {
        if (y % 10) y /= 10;
        else return false;
    }
    return true;
}

vector<int> getNoZeroIntegers(int n) {
    int x = 1, y = n - 1;
    while (x <= y) {
        if (check(x, y)) break;
        x++, y--;
    }
    return {x, y};
}

int main() {
    return 0;
}
