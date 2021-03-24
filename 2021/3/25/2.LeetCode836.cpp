/*************************************************************************
	> File Name: 2.LeetCode836.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月25日 星期四 00时26分37秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    int xmin = max(rec1[0], rec2[0]);
    int ymin = max(rec1[1], rec2[1]);
    int xmax = min(rec1[2], rec2[2]);
    int ymax = min(rec1[3], rec2[3]);
    if (xmin >= xmax || ymin >= ymax) return false;
    return true;
}

int main() {
    return 0;
}
