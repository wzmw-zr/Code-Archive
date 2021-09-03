/*************************************************************************
	> File Name: 2.LeetCode1985.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月03日 星期五 14时11分15秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string kthLargestNumber(vector<string>& nums, int k) {
    auto cmp = [](string x, string y) -> decltype(auto) {
        if (x.size() != y.size()) return x.size() > y.size();
        return x > y;
    };
    sort(nums.begin(), nums.end(), cmp);
    return nums[k - 1];
}

int main() {
    return 0;
}
