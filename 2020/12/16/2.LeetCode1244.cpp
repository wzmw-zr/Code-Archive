/*************************************************************************
	> File Name: 2.LeetCode1244.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月16日 星期三 09时47分34秒
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

class Leaderboard {
public:
    unordered_map<int, int> user;
    map<int, int> scores;

    Leaderboard() {}

    void addScore(int playerId, int score) {
        if (!user.count(playerId)) {
            user[playerId] = score * (-1);
            scores[user[playerId]]++;
        } else {
            scores[user[playerId]]--;
            user[playerId] -= score;
            scores[user[playerId]]++;
        }
    }

    int top(int K) {
        int ans = 0;
        for (auto &&[score, cnt] : scores) {
            if (!K) break;
            int temp = K > cnt ? cnt : K;
            ans += score * temp * (-1);
            K -= temp;
        }
        return ans;
    }

    void reset(int playerId) {
        scores[user[playerId]]--;
        user[playerId] = 0;
        scores[0]++;
    }
};

int main() {
    return 0;
}
