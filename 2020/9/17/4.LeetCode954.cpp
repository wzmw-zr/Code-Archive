/*************************************************************************
	> File Name: 4.LeetCode954.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月17日 星期四 18时50分29秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

bool canReorderDoubled(vector<int>& A) {
    map<int, int> p_mp;
    map<int, int> n_mp;
    for (auto &x : A) {
        if (x >= 0) p_mp[x]++;
        else n_mp[x * -1]++;
    }
    for (auto &x : p_mp) {
        if (p_mp.find(x.first * 2) != p_mp.end()) {
            if (x.second > p_mp[x.first * 2]) return false;
            p_mp[x.first * 2] -= x.second;
            x.second = 0;
        } else {
            if (x.second) return false;
        }
    }
    for (auto &x : p_mp) {
        if (x.second) return false;
    }
    for (auto &x : n_mp) {
        if (n_mp.find(x.first * 2) != n_mp.end()) {
            if (x.second > n_mp[x.first * 2]) return false;
            n_mp[x.first * 2] -= x.second;
            x.second = 0;
        } else {
            if (x.second) return false;
        }
    }
    for (auto &x : n_mp) {
        if (x.second) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) cin >> A[i];
    cout << (canReorderDoubled(A) ? "True" : "False") << endl;
    return 0;
}
