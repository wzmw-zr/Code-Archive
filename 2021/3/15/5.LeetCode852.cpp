/*************************************************************************
	> File Name: 5.LeetCode852.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月15日 星期一 20时15分24秒
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

int peakIndexInMountainArray(vector<int>& arr) {
    int l = 0, r = (int) arr.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] < arr[mid + 1]) l = mid + 1;
        else r = mid;
    }
    return l;
}

#if 0
int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) continue;
        return i;
    }
    return n;
}
#endif 

int main() {
    return 0;
}
