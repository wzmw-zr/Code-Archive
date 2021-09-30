/*************************************************************************
	> File Name: 1.LeetCode223.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月30日 星期四 08时17分31秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int x1 = max(ax1, bx1), y1 = max(ay1, by1), x2 = min(ax2, bx2), y2 = min(ay2, by2);
    int inter = max(0, x2 - x1) * max(0, y2 - y1);
    return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - inter;
}


int main() {
    return 0;
}
