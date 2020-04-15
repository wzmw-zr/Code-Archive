/*************************************************************************
	> File Name: case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月15日 星期三 19时07分58秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

vector<int> GetAns() {
    vector<int> ret;
    for (int i = 1; i <= 100; i++) ret.push_back(i);
    return ret;
}

typedef struct cmp {
    bool operator() (int a, int b) {
        return a < b;
    }
} cmp;

int main() {
    priority_queue<int, vector<int>, cmp> que;
    string tmp, key;
    getline(cin, tmp);
    getline(cin, key);
    cout << tmp.size() << endl;
    cout << key << endl;
    vector<int> ans = GetAns();
    printf("size = %d\n", ans.size());
    return 0;
}

