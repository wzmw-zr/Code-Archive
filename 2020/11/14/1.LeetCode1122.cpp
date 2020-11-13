/*************************************************************************
	> File Name: 1.LeetCode1122.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月14日 星期六 00时04分59秒
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

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> mp;
    for (int i = 0; i < arr2.size(); i++) mp[arr2[i]] = i;
    auto cmp = [&](int x, int y){
        if (!mp.count(x) && !mp.count(y)) return x < y;
        if (mp.count(x) && mp.count(y)) return mp[x] < mp[y];
        if (mp.count(x)) return true;
        return false;
    };
    sort(arr1.begin(), arr1.end(), cmp);
    return arr1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];
    auto ans = relativeSortArray(arr1, arr2);
    for (auto &x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
