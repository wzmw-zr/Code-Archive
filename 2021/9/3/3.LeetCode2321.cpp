/*************************************************************************
	> File Name: 3.LeetCode2321.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月03日 星期五 08时41分14秒
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

void quick_select(vector<int> &arr, int left, int right, int k) {
    if (left >= right) return ;
    int l = left, r = right;
    int num = arr[left];
    while (l < r) {
        while ((l < r) && (arr[r] >= num)) r--;
        if (l < r) arr[l++] = arr[r];
        while ((l < r) && (arr[l] < num)) l++;
        if (l < r) arr[r--] = arr[l];
    }
    arr[l] = num;
    if (l - left + 1 >= k) quick_select(arr, left, l, k);
    else quick_select(arr, l + 1, right, k - (l - left + 1));
}

vector<int> smallestK(vector<int> &arr, int k) {
    quick_select(arr, 0, static_cast<int>(arr.size()) - 1, k);
    return vector<int>(arr.begin(), arr.begin() + k);
}

int main() {
    return 0;
}
