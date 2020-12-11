/*************************************************************************
	> File Name: 1.LeetCode649.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月11日 星期五 08时34分55秒
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

int dfs(string &senate, vector<int> &check, int ind, int radiant, int dire) {
    if (ind >= senate.size()) return 1;
    if (check[ind]) return dfs(senate, check, ind + 1, radiant, dire);
    if (senate[ind] == 'R') {
        if (dire == 0) return 1;
        check[ind] = 1;
        int ans = 0;
        for (int i = ind + 1; senate[i] && !ans; i++) {
            if (senate[i] == 'R') continue;
            check[i] = 1;
            ans = dfs(senate, check, ind + 1, radiant - 1, dire - 1);
            check[i] = 0;
        }
        check[ind] = 0;
        return ans;
    } else {
        if (radiant == 0) return 1;
        check[ind] = 1;
        int ans = 0;
        for (int i = ind + 1; senate[i] && !ans; i++) {
            if (senate[i] == 'D') continue;
            check[i] = 1;
            ans = dfs(senate, check, ind + 1, radiant - 1, dire - 1);
            check[i] = 0;
        }
        check[ind] = 0;
        return ans;
    }
    return 1;
}

string predictPartyVictory(string senate) {
    int n = senate.size();
    int radiant, dire;
    for (char c : senate) {
        if (c == 'R') radiant++;
        else dire++;
    }
    vector<int> check(n, 0);
    if (dfs(senate, check, 0, radiant, dire)) {
        if (senate[0] == 'R') return "Radiant";
        else return "Dire";
    }
    if (senate[0] == 'R') return "Dire";
    return "Radiant";
}

int main() {
    string senate;
    cin >> senate;
    cout << predictPartyVictory(senate) << endl;
    return 0;
}
