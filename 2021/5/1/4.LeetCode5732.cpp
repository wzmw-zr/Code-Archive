/*************************************************************************
	> File Name: 4.LeetCode5732.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月01日 星期六 22时37分43秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    arr[0] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] <= 1) continue;
        arr[i] = arr[i - 1] + 1;
    }
    return arr[n - 1];
}

int main() {
    return 0;
}
