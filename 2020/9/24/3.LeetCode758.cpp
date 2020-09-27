/*************************************************************************
	> File Name: 3.LeetCode758.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月24日 星期四 21时32分31秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<unistd.h>
using namespace std;

struct Area {
    int x, y;
    
    Area(int x, int y) : x(x), y(y) {}

    bool operator<(const Area &b) {
        return this->x == b.x ? this->y < b.y : this->x < b.x;
    }
};

string boldWords(vector<string>& words, string S) {
    vector<Area> area, true_area;
    for (int i = 0; S[i]; i++) {
        for (auto &x : words) {
            int j = 0;
            for (j = 0; x[j]; j++) {
                if (S[i + j] != x[j]) break;
            }
            if (!x[j]) area.push_back({i, i + j - 1});
        }
    }
    for (auto &x : area) cout << x.x << " " << x.y << endl;
    cout << endl;
    sort(area.begin(), area.end());
    for (auto &x : area) cout << x.x << " " << x.y << endl;
    cout << endl;
    for (auto &x : area) {
        if (true_area.empty()) true_area.push_back(x);
        else {
            Area temp = true_area[true_area.size() - 1];
            if (temp.y + 1 < x.x) {
                true_area.push_back(x);
            } else {
                true_area.pop_back();
                true_area.push_back({temp.x, max(temp.y, x.y)});
            }
        }
    }
    for (auto &x : true_area) cout << x.x << " " << x.y << endl;
    string ans = "";
    for (int i = 0; S[i]; ) {
        for (auto &x : true_area) {
            while (i < x.x) ans += S[i++];
            ans += "<b>";
            while (i <= x.y) ans += S[i++];
            ans += "</b>";
        }
        for (; S[i]; i++) ans += S[i];
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    string s;
    vector<string> words;
    for (int i = 0; i < n; i++) {
        cin >> s;
        words.push_back(s);
    }
    cin >> s;
    cout << boldWords(words, s) << endl;
    return 0;
}
