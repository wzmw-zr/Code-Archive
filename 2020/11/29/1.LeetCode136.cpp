/*************************************************************************
	> File Name: 1.LeetCode136.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月29日 星期日 08时33分22秒
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

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int &x : nums) ans ^= x;
    return ans;
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    cout << singleNumber(nums) << endl;
    return 0;
}
