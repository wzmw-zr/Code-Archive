/*************************************************************************
	> File Name: 1.LeetCode232.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月05日 星期五 00时02分16秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1, s2;
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int ret = s2.top();
        s2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return ret;
    }

    /** Get the front element. */
    int peek() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int ret = s2.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return ret;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

int main() {
    return 0;
}
