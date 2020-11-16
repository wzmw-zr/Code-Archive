/*************************************************************************
	> File Name: 3.LeetCode658.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月17日 星期二 00时34分33秒
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

struct Node {
    int val, dis;
    Node() = default;
    Node(int val, int dis) : val(val), dis(dis) {}
    bool operator<(const struct Node &a) const {
        return this->dis == a.dis ? this->val > a.val : this->dis > a.dis;
    }
};

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<Node> que;
    vector<int> ans;
    for (int num : arr) que.push({num, abs(num - x)});
    while (k--) {
        ans.push_back(que.top().val);
        que.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int k, x, n;
    vector<int> arr;
    cin >> k >> x;
    while (cin >> n)  arr.push_back(n);
    auto ans = findClosestElements(arr, k, x);
    for (int y : ans) cout << y << " ";
    cout << endl;
    return 0;
}
