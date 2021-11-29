/*************************************************************************
	> File Name: 3.LeetCode786.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月29日 星期一 09时52分51秒
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

int check(vector<int> &arr, double val) {
    int n = arr.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int l = 0, r = i - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (arr[mid] * 1.0 / arr[i] <= val) l = mid;
            else r = mid - 1;
        }
        ans += l + (arr[l] * 1.0 / arr[i] <= val ? 1 : 0);
    }
    return ans;
}

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int n = arr.size();
    double l = 0, r = 1;
    while (1) {
        double mid = (l + r) * 1.0 / 2;
        int cnt = check(arr, mid);
        cout << cnt << endl;
        if (cnt == k) break;
        if (cnt < k) l = mid;
        else r = mid;
    }
    double val = (l + r) / 2;
    int p = 0, q = 0, flag = 0;
    for (int i = 1; i < n; i++) {
        int x = 0, y = i - 1;
        while (x < y) {
            int mid = (x + y + 1) / 2;
            if (arr[mid] * 1.0 / arr[i] <= val) x = mid;
            else y = mid - 1;
        }
        if (arr[x] * 1.0 / arr[i] > val) continue;
        if (!flag) {
            p = x, q = i;
            flag = 1;
        } 
        if (arr[x] * arr[q] > arr[p] * arr[i]) p = x, q = i;
    }
    return {arr[p], arr[q]};
}

int main() {
    return 0;
}
