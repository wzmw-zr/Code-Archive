/*************************************************************************
	> File Name: 2.LeetCode1620.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月19日 星期二 22时32分30秒
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
#include<cmath>
using namespace std;

typedef pair<double, double> PII;

vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    unordered_map<string, int> mp;
    unordered_map<string, PII> hash;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            PII node(i, j);
            string name = to_string(i) + "," + to_string(j);
            mp[name] = 0;
            hash[name] = node;
            for (auto &x : towers) {
                double dis = sqrt((i - x[0]) * (i - x[0]) + (j - x[1]) * (j - x[1]));
                if (dis > radius) continue;
                mp[name] += (int) (x[2] / (1 + dis));
            }
        }
    }
    PII ans(0, 0);
    int num = -1;
    for (auto &&[s, cnt] : mp) {
        if (cnt < num) continue;
        if (cnt > num) {
            ans = hash[s];
            num = cnt;
            continue;
        }
        ans = min(ans, hash[s]);
    }
    return vector<int>({(int) ans.first, (int) ans.second});
}

int main() {
    return 0;
}
