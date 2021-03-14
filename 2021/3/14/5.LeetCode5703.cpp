/*************************************************************************
	> File Name: 5.LeetCode5703.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月14日 星期日 10时41分16秒
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

struct Class {
    double pass;
    double total;
    double up;
    Class() = default;
    Class(int pass, int total) : pass(pass), total(total) {
        cal_up();
    }
    void cal_up() {
        up = (pass + 1) / (total + 1) - pass / total;
    }
    bool operator<(const struct Class &a) const {
        return this->up < a.up;
    }
};

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    priority_queue<Class> que;
    for (auto &x : classes) que.push(Class(x[0], x[1]));
    while (extraStudents--) {
        auto temp = que.top();
        que.pop();
        temp.pass++, temp.total++;
        temp.cal_up();
        que.push(temp);
    }
    double total = 0.0;
    double n = classes.size();
    while (!que.empty()) {
        auto temp = que.top();
        que.pop();
        total += temp.pass / temp.total;
    }
    return total / n;
}

int main() {
    return 0;
}
