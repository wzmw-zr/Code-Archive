/*************************************************************************
	> File Name: 1.LeetCode295.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月27日 星期五 08时38分27秒
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

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {}

    void addNum(int num) {
        if (left.empty()) {
            left.push(num);
        } else if (num <= left.top()) {
            if (left.size() > right.size()) {
                right.push(left.top());
                left.pop();
            }
            left.push(num);
        } else if (right.empty()) {
            right.push(num);
        } else if (num >= right.top()) {
            if (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            } 
            right.push(num);
        } else {
            if (left.size() <= right.size()) left.push(num);
            else right.push(num);
        }
    }

    double findMedian() {
        if (left.empty() && right.empty()) return 0.0;
        int l = left.size(), r = right.size();
        if (l == r) return (1.0 * left.top() + 1.0 * right.top()) / 2.0;
        else if (l > r) return left.top();
        return right.top();
    }
};

int main() {
    return 0;
}
