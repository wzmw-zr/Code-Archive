/*************************************************************************
	> File Name: 1.LeetCode983.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月06日 星期三 07时22分25秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unistd.h>
using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs) {
    int cost = 0;
    for (int i = 0; i < days.size(); ) {
        int week[5] = {0}, month = 0, j, week_end_ind[5] = {0};
        for (j = i; j < days.size(); j++) {
            if (days[j] - days[i] + 1 > 30) break;
            int tmp = (days[j] - days[i]) / 7;
            switch (tmp) {
                case 0: week[0]++; week_end_ind[0] = j; break;
                case 1: week[1]++; week_end_ind[1] = j; break;
                case 2: week[2]++; week_end_ind[2] = j; break;
                case 3: week[3]++; week_end_ind[3] = j; break;
                case 4: week[4]++; week_end_ind[4] = j; break;
            }
        }
        month = week[0] + week[1] + week[2] + week[3] + week[4];
        int day_cost = costs[0] * month;
        int week_cost = costs[1] * 4 + max(costs[0] * 2, costs[1]);
        int month_cost = costs[2];
        if (month_cost <= day_cost && month_cost <= week_cost) {
            cost += month_cost;
            i = j;
            continue;
        }
        if (costs[1] < costs[0] * week[0]) {
            cost += costs[1];
        } else {
            cost += costs[0] * week[0];
        }
        i = week_end_ind[0] + 1;
    }
    return cost;
}

int main() {
    int n, tmp;
    vector<int> days, costs;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        days.push_back(tmp);
    }
    for (int i = 0; i < 3; i++) {
        cin >> tmp;
        costs.push_back(tmp);
    }
    for (int i = 0; i < n; i++) cout << days[i] << " ";
    cout << endl;
    for (int i = 0; i < 3; i++) cout << costs[i] << " ";
    cout << endl;
    cout << mincostTickets(days, costs) << endl;
    return 0;
}
