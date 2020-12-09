/*************************************************************************
	> File Name: 4.LeetCode1311.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月09日 星期三 17时46分59秒
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
    int id;
    int level;
    Node() = default;
    Node(int id, int level) : id(id), level(level) {}
};

typedef pair<int, string> PIS;

vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
    int n = friends.size();
    vector<int> check(n, 0);
    queue<Node> que;
    que.push(Node(id, 0));
    check[id] = 1;
    vector<int> level_k_friends;
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        if (temp.level > level) continue;
        if (temp.level == level) level_k_friends.push_back(temp.id);
        for (int &x : friends[temp.id]) {
            if (check[x]) continue;
            check[x] = 1;
            que.push(Node(x, temp.level + 1));
        }
    }
    unordered_map<string, int> mp;
    unordered_set<string> st;
    for (int &x : level_k_friends) {
        for (string &s : watchedVideos[x]) {
            mp[s]++;
            st.insert(s);
        }
    }
    vector<PIS> videos;
    for (string s : st) videos.push_back(PIS(mp[s], s));
    sort(videos.begin(), videos.end());
    vector<string> ans;
    for (auto &x : videos) ans.push_back(x.second);
    return ans;
}

int main() {
    return 0;
}
