/*************************************************************************
	> File Name: 1.LeetCode703.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月11日 星期四 00时01分27秒
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

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> que;
    int K;
    KthLargest(int k, vector<int>& nums) : K(k) {
        for (int &x : nums) {
            if (que.size() < K)  que.push(x);
            else {
                if (x <= que.top()) continue;
                que.pop();
                que.push(x);
            }
        }
    }

    int add(int val) {
        if (que.size() < K) que.push(val);
        else {
            if (val > que.top()) {
                que.pop();
                que.push(val);
            }
        }
        return que.top();
    }
};

int main() {
    return 0;
}
