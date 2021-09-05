/*************************************************************************
	> File Name: 1.LeetCode1588.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月29日 星期日 08时06分37秒
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

int sumOddLengthSubarrays(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;
    vector<int> nums(n + 1, 0);
    for (int i = 0; i < n; i++) nums[i + 1] = nums[i] + arr[i];
    for (int i = 1; i <= n; i += 2) {
        for (int j = i; j <= n; j++) ans += nums[j] - nums[j - i];
    }
    return ans;
}

int main() {
    vector<int> arr;
    int n;
    while (cin >> n) arr.push_back(n);
    cout << sumOddLengthSubarrays(arr) << endl;
    return 0;
}
