/*************************************************************************
	> File Name: 5.LeetCode155.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月23日 星期三 10时27分43秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class MinStack {
public:
    vector<int> nums;
    MinStack() {}

    void push(int x) {
        nums.push_back(x);
    }

    void pop() {
        nums.pop_back();
    }

    int top() {
        return *nums.rbegin();
    }

    int getMin() {
        int ans = INT32_MIN;
        for (int &x : nums) ans = max(ans, x);
        return ans;
    }
};

int main() {
    return 0;
}
