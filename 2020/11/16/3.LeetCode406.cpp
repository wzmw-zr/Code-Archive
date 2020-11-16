/*************************************************************************
	> File Name: 3.LeetCode406.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月16日 星期一 09时47分17秒
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

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> ans;
    sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b){ return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; });
    for (auto &x : people) ans.insert(ans.begin() + x[1], x);
    return ans;
}

int main() {
    return 0;
}
