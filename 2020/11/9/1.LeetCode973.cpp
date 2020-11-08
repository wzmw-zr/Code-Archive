/*************************************************************************
	> File Name: 1.LeetCode973.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月09日 星期一 00时04分09秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<vector<int>> ans;
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){ return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]); });
    for (int i = 0; i < K; i++) ans.push_back(points[i]);
    return ans;
}

int main() {
    return 0;
}
