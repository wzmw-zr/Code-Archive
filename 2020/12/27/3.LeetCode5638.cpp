/*************************************************************************
	> File Name: 3.LeetCode5638.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月27日 星期日 10时35分30秒
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

struct Apple {
    int cnt;
    int expire_day;
    Apple() = default;
    Apple(int cnt, int expire_day) : cnt(cnt), expire_day(expire_day) {}
    bool operator<(const struct Apple &a) const {
        return this->expire_day > a.expire_day;
    }
};

int eatenApples(vector<int>& apples, vector<int>& days) {
    int ans = 0, n = apples.size();
    priority_queue<Apple> que;
    for (int i = 0; i < n; i++) {
        while (!que.empty() && que.top().expire_day <= i) que.pop();
        if (que.empty()) {
            if (apples[i] == 0 && days[i] == 0) continue;
        } 
        que.push(Apple(apples[i], i + days[i]));
        ans++;
        Apple temp = que.top();
        que.pop();
        if (--temp.cnt) que.push(temp);
    }
    int day = n;
    while (!que.empty()) {
        while (!que.empty() && que.top().expire_day <= n) que.pop();
        if (que.empty()) break;
        ans++;
        n++;
        Apple temp = que.top();
        que.pop();
        if (--temp.cnt) que.push(temp);
    }
    return ans;
}

int main() {
    return 0;
}
