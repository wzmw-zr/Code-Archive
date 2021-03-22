/*************************************************************************
	> File Name: 1.LeetCode341.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月23日 星期二 00时05分22秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    vector<int> nums;
    int ind;

    NestedIterator(vector<NestedInteger> &nestedList) {
        ind = 0;
        for (auto &x : nestedList) dfs(x);
    }

    void dfs(NestedInteger &integer) {
        if (integer.isInteger()) nums.push_back(integer.getInteger());
        else {
            auto list = integer.getList();
            for (auto &x : list) dfs(x);
        }
    }

    int next() {
        return nums[ind++];
    }

    bool hasNext() {
        return ind < (int) nums.size();
    }
};

int main() {
    return 0;
}
