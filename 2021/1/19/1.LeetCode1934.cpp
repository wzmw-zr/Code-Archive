/*************************************************************************
	> File Name: 1.LeetCode1934.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月19日 星期二 15时27分02秒
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

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_top_heap;
    priority_queue<int, vector<int>, greater<int>> min_top_heap;
    MedianFinder() {}

    void addNum(int num) {
        if (max_top_heap.empty()) {
            max_top_heap.push(num);
            return ;
        }
        if (num >= max_top_heap.top()) {
            if (max_top_heap.size() > min_top_heap.size()) {
                min_top_heap.push(num);
                return ;
            } 
            if (num <= min_top_heap.top()) {
                max_top_heap.push(num);
                return ; 
            }
            max_top_heap.push(min_top_heap.top());
            min_top_heap.pop();
            min_top_heap.push(num);
            return ;
        }
        if (max_top_heap.size() == min_top_heap.size()) {
            max_top_heap.push(num);
            return ;
        }
        min_top_heap.push(max_top_heap.top());
        max_top_heap.pop();
        max_top_heap.push(num);
    }

    double findMedian() {
        if (max_top_heap.size() == 0) return 0;
        if (max_top_heap.size() > min_top_heap.size()) return max_top_heap.top();
        double ans = max_top_heap.top() + min_top_heap.top();
        return ans / 2;
    }
};

int main() {
    return 0;
}
