/*************************************************************************
	> File Name: 2.LeetCode5789.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月20日 星期日 10时35分22秒
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
#include <cmath>
using namespace std;

struct Node {
    int hour;
    int minute;

    Node() = default;

    Node(string t) {
        hour = stoi(t.substr(0, 2));
        minute = stoi(t.substr(3, 2));
    }

    bool operator<(const struct Node &that) const {
        return this->hour == that.hour ? this->minute < that.minute : this->hour < that.hour;
    }
};

int numberOfRounds(string startTime, string finishTime) {
    Node start = Node(startTime), finish = Node(finishTime);
    if (finish < start) finish.hour += 24;
    int cnt = 0;
    if (start.hour == finish.hour) {
        int l = int(ceil((float) start.minute / 15.0));
        int r = int(floor((float) finish.minute / 15.0));
        if (l >= r) return 0;
        return r - l;
    }
    cnt += 4 - int(ceil((float) start.minute / 15.0)) + int(floor((float) finish.minute / 15.0));
    start.hour++;
    cnt += (finish.hour - start.hour) * 4;
    return cnt;
}

int main() {
    return 0;
}
