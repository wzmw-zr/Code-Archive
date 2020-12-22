/*************************************************************************
	> File Name: 3.LeetCode346.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月22日 星期二 08时45分27秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class MovingAverage {
public:
    deque<int> que;
    int size;
    double sum;

    MovingAverage(int size) : size(size), sum(0) {}

    double next(int val) {
        if (que.size() < size) {
            que.push_back(val);
            sum += val;
            return sum / (int) que.size();
        }
        sum -= que.front();
        que.pop_front();
        que.push_back(val);
        sum += val;
        return sum / size;
    }
};

int main() {
    return 0;
}
