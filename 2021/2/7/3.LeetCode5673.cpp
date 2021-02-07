/*************************************************************************
	> File Name: 3.LeetCode5673.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月07日 星期日 10时41分32秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int maximumScore(int a, int b, int c) {
    priority_queue<int> que;
    que.push(a);
    que.push(b);
    que.push(c);
    int zero = 0, ans = 0;
    while (zero < 2) {
        int x_1 = que.top();
        que.pop();
        int x_2 = que.top();
        que.pop();
        ans++, x_1--, x_2--;
        if (x_1) que.push(x_1);
        else zero++;
        if (x_2) que.push(x_2);
        else zero++;
    }
    return ans;
}

int main() {
    return 0;
}
