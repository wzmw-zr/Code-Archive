/*************************************************************************
	> File Name: 3.LeetCode1395.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月17日 星期日 11时05分21秒
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
    int ind;
    int val;
    Node() = default;
    Node(int ind, int val) : ind(ind), val(val) {}
    bool operator<(const struct Node &a) const {
        return this->val < a.val;
    }
};

void merge(vector<Node> &nodes, vector<int> &cnt, int left, int right) {
    if (left >= right) return ;
    int mid = (left + right) / 2;
    vector<Node> temp;
    int x = left, y = mid + 1;
    while (x <= mid || y <= right) {
        if (x <= mid && ((y > right) || (nodes[x] < nodes[y]))) {
            cnt[nodes[x].ind] += (y - mid - 1);
            temp.push_back(nodes[x++]);
        } else {
            temp.push_back(nodes[y++]);
        }
    }
    for (int i = left, j = 0; i <= right; i++, j++) nodes[i] = temp[j];
} 

void merge_sort(vector<Node> &nodes, vector<int> &cnt, int left, int right) {
    if (left >= right) return ;
    int mid = (left + right) / 2;
    merge_sort(nodes, cnt, left, mid);
    merge_sort(nodes, cnt, mid + 1, right);
    merge(nodes, cnt, left, right);
}

int numTeams(vector<int>& rating) {
    int n = rating.size();
    vector<Node> nodes;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) nodes.push_back(Node(i, rating[i]));
    merge_sort(nodes, cnt, 0, n - 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (rating[i] > rating[j]) ans += cnt[j];
            else ans += n - 1 - j - cnt[j];
        }
    }
    return ans;
}

int main() {
    return 0;
}
