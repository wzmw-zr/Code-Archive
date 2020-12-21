/*************************************************************************
	> File Name: 3.LeetCode1765.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月21日 星期一 08时17分05秒
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
    priority_queue<int> max_top_heap;
    priority_queue<int, vector<int>, greater<int>> min_top_heap;

    MedianFinder() {}

    void addNum(int num) {
        if (!max_top_heap.size() || !min_top_heap.size()) {
            if (!max_top_heap.size()) max_top_heap.push(num);
            else {
                int min_max = max_top_heap.top();
                if (num > min_max) min_top_heap.push(num);
                else {
                    max_top_heap.pop();
                    max_top_heap.push(num);
                    min_top_heap.push(min_max);
                }
            }
            return ;
        }

        if (max_top_heap.size() == min_top_heap.size()) {
            int max_min = min_top_heap.top();
            int min_max = max_top_heap.top();
            if (num <= max_min) max_top_heap.push(num);
            else {
                min_top_heap.pop();
                min_top_heap.push(num);
                max_top_heap.push(max_min);
            }
        } else {
            int min_max = max_top_heap.top();
            if (num <= min_max) {
                max_top_heap.pop();
                max_top_heap.push(num);
                min_top_heap.push(min_max);
            } else {
                min_top_heap.push(num);
            }
        }
    }

    double findMedian() {
        if (!min_top_heap.size() || !max_top_heap.size()) {
            if (!max_top_heap.size()) return 0;
            return max_top_heap.top();
        }
        if (min_top_heap.size() == max_top_heap.size()) {
            double temp = max_top_heap.top() + min_top_heap.top();
            return temp / 2;
        } 
        return max_top_heap.top();
    }
};

int main() {
    return 0;
}
