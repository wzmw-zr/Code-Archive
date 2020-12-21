/*************************************************************************
	> File Name: 5.LeetCode1472.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月14日 星期一 19时43分47秒
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

class BrowserHistory {
public:
    vector<string> record; 
    int ind;

    BrowserHistory(string homepage) {
        ind = 0;
        record.push_back(homepage);
    }

    void visit(string url) {
        while ((ind + 1) != record.size()) record.pop_back();
        record.push_back(url);
        ind++;
    }

    string back(int steps) {
        ind = (ind - steps >= 0 ? ind - steps : 0);
        return record[ind];
    }

    string forward(int steps) {
        ind = (ind + steps < record.size() ? ind + steps : record.size() - 1);
        return record[ind];
    }
};

int main() {
    return 0;
}
