/*************************************************************************
	> File Name: 4.LeetCode5653.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月17日 星期日 14时42分27秒
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

int countGoodRectangles(vector<vector<int>>& rectangles) {
    int mmax = min(rectangles[0][0], rectangles[0][1]), cnt = 1, n = rectangles.size();
    for (int i = 1; i < n; i++) {
        int temp = min(rectangles[i][0], rectangles[i][1]);
        if (mmax > temp) continue;
        if (mmax == temp) cnt++;
        else mmax = temp, cnt = 1;
    }
    return cnt;
}

int main() {
    return 0;
}
