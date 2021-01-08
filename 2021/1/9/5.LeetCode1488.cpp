/*************************************************************************
	> File Name: 5.LeetCode1488.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月09日 星期六 01时22分35秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();
    vector<int> ans(n);
    unordered_map<int, int> mp;
    deque<int> extract;
    for (int i = 0; i < n; i++) {
        if (rains[i]) {
            ans[i] = -1;
            if (mp.count(rains[i])) {
                if (extract.empty()) return vector<int>(0);
                if (extract.back() < mp[rains[i]]) return vector<int>(0);
                auto iter = extract.begin();
                while (*iter < mp[rains[i]]) iter++;
                ans[*iter] = rains[i];
                extract.erase(iter);
            }
            mp[rains[i]] = i;
            continue;
        } else extract.push_back(i);
    }
    while (!extract.empty()) {
        ans[extract.front()] = 1;
        extract.pop_front();
    }
    return ans;
}

#if 0
vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();
    vector<int> ans(n);
    unordered_map<int, int> mp;
    vector<int> extract;
    for (int i = 0; i < n; i++) {
        if (rains[i]) {
            ans[i] = -1;
            if (mp.count(rains[i])) {
                if (extract.empty()) return vector<int>(0);
                int last = extract.back();
                if (last < mp[rains[i]]) return vector<int>(0);
                for (auto iter = extract.begin(); iter != extract.end(); iter++) {
                    if (*iter < mp[rains[i]]) continue;
                    ans[*iter] = rains[i];
                    ans.erase(iter);
                    break;
                }
            }
            mp[rains[i]] = i;
            continue;
        } else extract.push_back(i);
    }
    while (!extract.empty()) {
        ans[extract.front()] = 1;
        extract.erase(extract.begin());
    }
    return ans;
}
#endif

int main() {
    return 0;
}
