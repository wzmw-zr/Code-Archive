/*************************************************************************
	> File Name: 3.LeetCode5908.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月24日 星期日 10时56分03秒
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

struct Node {
    long id;
    long score;
    long size;
    long degree;
    vector<long> next;

    Node() : id(0), score(1), size(1), degree(0) {}
    Node(long id) : id(id), score(1), size(1), degree(0) {}
};

int countHighestScoreNodes(vector<int>& parents) {
    long wzmw_zr_q3 = 0;
    long n = parents.size();
    vector<Node> nodes(n);
    for (long i = 1; i < n; i++) {
        nodes[i].id = i;
        nodes[parents[i]].next.push_back(i);
        nodes[parents[i]].degree++;
    }
    queue<long> que;
    for (long i = 0; i < n; i++) {
        if (nodes[i].next.size() == 0) que.push(i);
    }
    while (!que.empty()) {
        long t = que.front();
        que.pop();
        long score = 1;
        long cnt = 1;
        for (long x : nodes[t].next) {
            cnt += nodes[x].size;
            score *= nodes[x].size;
        }
        if (t != 0) {
            nodes[parents[t]].size += nodes[t].size;
            score *= n - cnt;
            if (!(--nodes[parents[t]].degree)) que.push(parents[t]);
        }
        nodes[t].score = score;
    }

    for (long i = 0; i < n; i++) cout << nodes[i].score << " ";
    cout << endl;

    long mmax = INT64_MIN;
    for (long i = 0; i < n; i++) mmax = max(mmax, nodes[i].score);
    long ans = 0;
    for (long i = 0; i < n; i++) ans += mmax == nodes[i].score ? 1 : 0;
    return ans;
}

long main() {
    vector<int> parents;
    int n;
    while (cin >> n) parents.push_back(n);
    cout << countHighestScoreNodes(parents) << endl;
    return 0;
}
