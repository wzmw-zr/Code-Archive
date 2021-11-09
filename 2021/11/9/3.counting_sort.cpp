/*************************************************************************
	> File Name: 3.counting_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月09日 星期二 17时05分21秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_N 1000

vector<int> counting_sort(vector<int> &nums) {
    int n = nums.size();
    vector<int> cnts(MAX_N + 1, 0);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) cnts[nums[i]]++;
    for (int i = 1; i <= MAX_N; i++) cnts[i] += cnts[i - 1];
    for (int i = n - 1; i >= 0; i--) ans[--cnts[nums[i]]] = nums[i];
    return ans;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    for (int x : nums) cout << x << " ";
    cout << endl;
    vector<int> ans = counting_sort(nums);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
