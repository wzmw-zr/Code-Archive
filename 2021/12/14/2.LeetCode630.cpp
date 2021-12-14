/*************************************************************************
	> File Name: 2.LeetCode630.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年12月14日 星期二 11时00分18秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int scheduleCourse(vector<vector<int>>& courses) {
    auto cmp = [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    };
    sort(courses.begin(), courses.end(), cmp);
    int ind = 0;
    priority_queue<vector<int>> que;
    for (auto &&course : courses) {
        if (course[0] > course[1]) continue;
        que.push(course);
        if (ind + course[0] <= course[1]) {
            ind += course[0];
            continue;
        }
        auto temp = que.top();
        que.pop();
        ind += course[0] - temp[0];
    }
    return que.size();
}

int main() {
    return 0;
}
