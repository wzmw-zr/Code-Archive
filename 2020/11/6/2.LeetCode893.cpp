/*************************************************************************
	> File Name: 2.LeetCode893.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月06日 星期五 13时24分04秒
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

string handle(string &A) {
    string odd = "", even = "";
    for (int i = 0; A[i]; i++) {
        if (i & 1) odd += A[i];
        else even += A[i];
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    return even + odd;
}

int numSpecialEquivGroups(vector<string>& A) {
    unordered_map<string, vector<string>> mp;
    for (auto &x : A) {
        string temp = handle(x);
        if (!mp.count(temp)) mp[temp] = vector<string>(0);
        mp[temp].push_back(x);
    }
    return mp.size();
}

int main() {
    string str;
    vector<string> A;
    while (cin >> str) A.push_back(str);
    cout << numSpecialEquivGroups(A) << endl;
    return 0;
}
