/*************************************************************************
	> File Name: 6.average.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月17日 星期一 21时36分30秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<numeric>
#include<algorithm>
using namespace std;

int n;

struct People {
    string name;
    double scores;

    People(string name, double scores) : name(name), scores(scores) {}

    bool operator<(const People &a) const {
        if (this->scores - a.scores) return this->scores < a.scores;
        return this->name > a.name;
    }
};

int main() {
    cin >> n;
    map<string, vector<double>> mp;
    string name;    
    double score;

    priority_queue<People> que;

    for (int i = 0; i < n; i++) {
        cin >> name >> score;
        if (mp.find(name) == mp.end()) {
            vector<double> tmp = {score};
            mp[name] = tmp;
        } else {
            mp[name].push_back(score);
        }
    }
    #if 0
    for (auto &x : mp) {
        cout << x.first << " : ";
        for (auto &y : x.second) {
            cout << y << ", ";
        }
        cout << endl;
    }
    #endif
    for (auto &x : mp) {
        sort(begin(x.second), end(x.second), [](double a, double b){ return a > b; });
        if (x.second.size() <= 5) {
            double sum = 0.0;
            for (auto y : x.second) sum += y;
            que.push({x.first, sum / x.second.size()});
        } else {
            double sum = 0.0;
            for (int i = 0; i < 5; i++) sum += x.second[i];
            sum /= 5;
            que.push({x.first, sum});
        }
    }
    while (!que.empty()) {
        People tmp = que.top();
        que.pop();
        printf("%s %.2f\n", tmp.name.c_str(), tmp.scores);
    }
    return 0;
}
