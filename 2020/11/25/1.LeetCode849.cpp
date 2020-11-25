/*************************************************************************
	> File Name: 1.LeetCode849.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月25日 星期三 08时52分30秒
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

int maxDistToClosest(vector<int>& seats) {
    int n = seats.size();
    vector<int> seated;
    vector<int> dis;
    for (int i = 0; i < n; i++) {
        if (seats[i]) seated.push_back(i);
    }
    int cnt = seated.size();
    int ans = max(seated[0], n - 1 - seated[cnt - 1]);
    for (int i = 0; i < cnt - 1; i++) ans = max(ans, (seated[i + 1] - seated[i]) / 2);
    return ans;
}

int main() {
    int n;
    vector<int> seats;
    while (cin >> n) seats.push_back(n);
    cout << maxDistToClosest(seats) << endl;
    return 0;
}
