/*************************************************************************
	> File Name: 2.LeetCode649.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月11日 星期五 09时04分06秒
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

string predictPartyVictory(string senate) {
    int n = senate.size();
    int radiant = 0, dire = 0;
    vector<int> check(n, 0);
    for (char c : senate) {
        if (c == 'R') radiant++;
        else dire++;
    }
    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        if (!radiant) return "Dire";
        if (!dire) return "Radiant";
        check[i] = 1;
        if (senate[i] == 'R') {
            for (int j = i + 1; j < n; j++) {
                if (senate[j] == 'R') continue;
                if (check[j]) continue;
                check[j] = 1;
                break;
            }
            radiant--, dire--;
            if (dire == 0) return "Radiant";
        } else {
            for (int j = i + 1; j < n; j++) {
                if (senate[j] == 'D') continue;
                if (check[j]) continue;
                check[j] = 1;
                break;
            }
            radiant--, dire--;
            if (radiant == 0) return "Dire";
        }
    }
    return "Radiant";
}

int main() {
    string senate;
    cin >> senate;
    cout << predictPartyVictory(senate) << endl;
    return 0;
}
