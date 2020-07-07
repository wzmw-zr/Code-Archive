/*************************************************************************
	> File Name: 1.LeetCode1666.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月08日 星期三 00时15分10秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;

vector<int> divingBoard(int shorter, int longer, int k) {
    set<int> st;
    vector<int> ret;
    for (int i = 0; i <= k; i++) {
        int len = shorter * i + longer * (k - i);
        st.insert(len);
    }
    for (auto x : st) {
        ret.push_back(x);
    }
    return ret;
}

int main() {
    int shorter, longer, k;
    cin >> shorter >> longer >> k;
    vector<int> ret = divingBoard(shorter, longer, k);
    for (auto x : ret) cout << x << " ";
    cout << endl;
    return 0;
}
