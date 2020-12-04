/*************************************************************************
	> File Name: 1.LeetCode621.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月05日 星期六 07时24分29秒
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
    bool operator<(const struct Node &a) const {
        return this->cnt > a.cnt;
    }
};

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> mp_1, mp_2;
    for (char &c : tasks) mp_1[c]++;
    int ans = 0;
    while (!mp_1.empty()) {
        vector<Node> temp;
        for (auto &x : mp_1) temp.push_back({x.first, x.second});
        sort(temp.begin(), temp.end());
        for (auto &x : temp) {
            if (mp_2.count(x.c)) continue;
            if (!(--mp_1[x.c])) mp_1.erase(mp_1.find(x.c));
            mp_2[x.c] = n + 1;
            break;
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            if (!mp_2.count(c)) continue;
            if (!(--mp_2[c])) mp_2.erase(mp_2.find(c));
        }
        ans++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    char c;
    vector<char> tasks;
    while (cin >> c) tasks.push_back(c);   
    cout << leastInterval(tasks, n) << endl;
    return 0;
}
