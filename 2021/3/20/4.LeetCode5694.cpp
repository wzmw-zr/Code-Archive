/*************************************************************************
	> File Name: 4.LeetCode5694.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月20日 星期六 22时37分26秒
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

class AuthenticationManager {
public:
    int timeToLive;
    unordered_map<int, unordered_set<string>> mp;
    unordered_map<string, int> msg;

    AuthenticationManager(int timeToLive) : timeToLive(timeToLive) {}

    void generate(string tokenId, int currentTime) {
        for (auto &&[t, v] : mp) {
            if (t + timeToLive <= currentTime) {
                for (auto s : v) msg.erase(s);
                mp[t].clear();
            }
        }
        if (!mp.count(currentTime)) mp[currentTime] = unordered_set<string>();
        mp[currentTime].insert(tokenId);
        msg[tokenId] = currentTime;
    }

    void renew(string tokenId, int currentTime) {
        for (auto &&[t, v] : mp) {
            if (t + timeToLive <= currentTime) {
                for (auto s : v) msg.erase(s);
                mp[t].clear();
            }
        }
        if (!msg.count(tokenId)) return ;
        int t = msg[tokenId];
        mp[t].erase(tokenId);
        if (!mp.count(currentTime)) mp[currentTime] = unordered_set<string>();
        mp[currentTime].insert(tokenId);
        msg[tokenId] = currentTime;
    }

    int countUnexpiredTokens(int currentTime) {
        for (auto &&[t, v] : mp) {
            if (t + timeToLive <= currentTime) {
                for (auto s : v) msg.erase(s);
                mp[t].clear();
            }
        }
        return msg.size();
    }
};

int main() {
    return 0;
}
