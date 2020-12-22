/*************************************************************************
	> File Name: 2.LeetCode1348.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月22日 星期二 08时10分04秒
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

class TweetCounts {
public:
    const int minute = 60;
    const int hour = 3600;
    const int day = 86400;

    unordered_map<string, vector<int>> mp;

    TweetCounts() {}

    void recordTweet(string tweetName, int time) {
        if (!mp.count(tweetName)) mp[tweetName] = {};
        mp[tweetName].push_back(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int dis;
        if (freq == "minute") dis = minute;
        else if (freq == "hour") dis = hour;
        else dis = day;
        int cnt = (endTime - startTime + 1) / dis + (((endTime - startTime + 1) % dis) ? 1 : 0);
        vector<int> ans(cnt, 0);
        for (int &x : mp[tweetName]) {
            if (x < startTime || x > endTime) continue;
            int ind = (x - startTime + 1) / dis + (((x - startTime + 1) % dis) ? 1 : 0);
            ans[ind - 1]++;
        }
        return ans;
    }
};

int main() {
    return 0;
}
