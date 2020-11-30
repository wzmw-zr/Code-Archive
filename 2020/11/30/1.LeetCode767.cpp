/*************************************************************************
	> File Name: 1.LeetCode767.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年11月30日 星期一 08时58分07秒
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
    char c;
    int cnt;
    Node() = default;
    Node(char c, int cnt) : c(c), cnt(cnt) {}
    Node(pair<char, int> x) : c(x.first), cnt(x.second) {}
    bool operator<(const struct Node &a) const {
        return this->cnt < a.cnt;
    }
};

string reorganizeString(string S) {
    unordered_map<char, int> mp;
    priority_queue<Node> que;
    string ans = "";
    int n = S.size();
    for (char c : S) mp[c]++;
    for (auto x : mp) {
        que.push(Node(x));
        if (x.second * 2 - 1 > n) return "";
    }
    while (!que.empty()) {
        Node temp_1 = que.top();
        que.pop();
        if (que.empty()) {
            ans += temp_1.c;
            temp_1.cnt--;
            break;
        }
        Node temp_2 = que.top();
        que.pop();
        ans += temp_1.c;
        ans += temp_2.c;
        if (--temp_1.cnt) que.push(temp_1);
        if (--temp_2.cnt) que.push(temp_2);
    }
    return ans;
} 

int main() {
    return 0;
}
