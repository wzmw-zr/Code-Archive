/*************************************************************************
	> File Name: 4.LeetCode716.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月23日 星期三 10时17分04秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

class MaxStack {
public:
    vector<int> nums;
    MaxStack() {}
    
    void push(int x) {
        nums.push_back(x);
    }
    
    int pop() {
        int ans = *nums.rbegin();
        nums.pop_back();
        return ans;
    }
    
    int top() {
        return *nums.rbegin();
    }
    
    int peekMax() {
        int ans = INT32_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < ans) continue;
            ans = nums[i];
        }
        return ans;
    }
    
    int popMax() {
        int ans = INT32_MIN;
        auto iter = nums.begin();
        for (auto it = nums.begin(); it != nums.end(); it++) {
            if (*it < ans) continue;
            ans = *it;
            iter = it;
        }
        nums.erase(iter);
        return ans;
    }
};

int main() {
    return 0;
}
