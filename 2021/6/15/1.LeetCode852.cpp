/*************************************************************************
	> File Name: 1.LeetCode852.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月15日 星期二 20时11分41秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();
    int l = 1, r = n - 2;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if ((arr[mid - 1] < arr[mid]) && (arr[mid] > arr[mid + 1])) return mid;
        if ((arr[mid - 1] < arr[mid]) && (arr[mid] < arr[mid + 1])) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    return 0;
}
