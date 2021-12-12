/*************************************************************************
	> File Name: 3.LeetCode5954.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月12日 星期日 22时00分15秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    int n = plants.size();
    int l = 0, r = n - 1;
    int cnt = 0;
    int remainA = capacityA, remainB = capacityB;
    while (l <= r) {
        if (l == r) {
            if (remainA >= remainB) {
                if (remainA < plants[l]) remainA = capacityA, cnt++;
                remainA -= plants[l];
                l++;
            } else {
                if (remainB < plants[l]) remainB = capacityB, cnt++;
                remainB -= plants[l];
                r--;
            }
            continue;
        }
        if (remainA < plants[l]) remainA = capacityA, cnt++;
        if (remainB < plants[r]) remainB = capacityB, cnt++;
        remainA -= plants[l];
        remainB -= plants[r];
        l++, r--;
    }
    return cnt;
}

int main() {
    return 0;
}
