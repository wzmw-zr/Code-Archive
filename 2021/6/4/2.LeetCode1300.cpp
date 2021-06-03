/*************************************************************************
	> File Name: 2.LeetCode1300.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月04日 星期五 00时12分22秒
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

int find_lowest_inds(vector<int> &arr, int l, int r, int num) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] >= num) r = mid;
        else l = mid + 1;
    }
    return l;
}

int findBestValue(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];
    int ans = arr[n - 1];
    int dis = INT32_MAX;
    for (int i = arr[n - 1]; i >= 0; i--) {
        int ind = find_lowest_inds(arr, 0, n - 1, i);
        int sum = pre[ind] + (n - ind) * i;
        int t = abs(sum - target);
        if (t <= dis) {
            dis = t;
            ans = i;
            continue;
        }
        break;
    }
    return ans;
}

int main() {
    return 0;
}
