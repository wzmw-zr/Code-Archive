/*************************************************************************
	> File Name: 4.LeetCode355.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月07日 星期一 18时46分30秒
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

typedef pair<int, int> PII;

struct User {
    int id;
    unordered_set<int> followee;
    vector<PII> twitter;
    User() = default;
    User(int id) : id(id) {
        followee.insert(id);
    }
};

class Twitter {
public:
    unordered_map<int, User *> mp;
    int stime;

    Twitter() : stime(0) {}

    void postTweet(int userId, int tweetId) {
        if (!mp.count(userId)) mp[userId] = new User(userId);
        mp[userId]->twitter.push_back(PII(stime++, tweetId));
    }

    vector<int> getNewsFeed(int userId) {
        vector<PII> ans;
        priority_queue<PII, vector<PII>, greater<PII>> que;
        if (!mp.count(userId)) mp[userId] = new User(userId);
        for (int x : mp[userId]->followee) {
            for (int i = 0, j = mp[x]->twitter.size() - 1; i < 10 && j >= 0; i++, j--) 
            {
                if (que.size() < 10) {
                    que.push(mp[x]->twitter[j]);   
                    continue;
                }
                if (mp[x]->twitter[j] < que.top()) break;
                que.pop();
                que.push(mp[x]->twitter[j]);
            }
        }
        while (!que.empty()) {
            ans.push_back(que.top());
            que.pop();
        }
        sort(ans.begin(), ans.end(), greater<PII>());
        vector<int> ret;
        for (auto &x : ans) ret.push_back(x.second);
        return ret;
    }

    void follow(int followerId, int followeeId) {
        if (!mp.count(followerId)) mp[followerId] = new User(followerId);
        if (!mp.count(followeeId)) mp[followeeId] = new User(followeeId);
        mp[followerId]->followee.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (!mp.count(followerId)) mp[followerId] = new User(followerId);
        if (!mp.count(followeeId)) mp[followeeId] = new User(followeeId);
        if (followerId == followeeId) return ;
        if (mp[followerId]->followee.count(followeeId)) 
            mp[followerId]->followee.erase(mp[followerId]->followee.find(followeeId));
    }
};

int main() {
    return 0;
}
