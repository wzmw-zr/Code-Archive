/*************************************************************************
	> File Name: 1.LeetCode1356.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月06日 星期五 00时04分48秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<algorithm>
using namespace std;

vector<int> sortByBits(vector<int>& arr) {
    auto cmp = [](int &a, int &b) {
        int a_t = a, b_t = b;
        int cnt_a = 0, cnt_b = 0;
        while (a_t) {
            cnt_a += a_t & 1;
            a_t >>= 1;
        }
        while (b_t) {
            cnt_b += b_t & 1;
            b_t >>= 1;
        }
        return cnt_a == cnt_b ? a < b : cnt_a < cnt_b;
    };
    sort(arr.begin(), arr.end(), cmp);
    return arr;
}

int main() {
    vector<int> arr;
    int n;
    while (cin >> n) arr.push_back(n);
    auto ans = sortByBits(arr);
    for (auto &x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
