/*************************************************************************
	> File Name: 2.LeetCode274.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月10日 星期四 08时42分59秒
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

struct BIT {
    int n;
    vector<int> nums;
    BIT() = default;
    BIT(int n) : n(n), nums(n + 1, 0) {}
    constexpr int lowbit(int x) { return x & -x; }
    void add(int ind) {
        while (ind <= n) {
            nums[ind]++;
            ind += lowbit(ind);
        }
    }
    int query(int ind) {
        int ans = 0;
        while (ind) {
            ans += nums[ind];
            ind -= lowbit(ind);
        }
        return ans;
    }
};

int hIndex(vector<int>& citations) {
    if (citations.size() == 0) return 0;
    sort(citations.begin(), citations.end(), [](int a, int b){ return a > b; });
    int mmax = citations[0] + 1;
    BIT bit(mmax);
    int ans = 0;
    for (int &x : citations) bit.add(mmax - x);
    for (int i = 0; i <= citations[0]; i++) {
        int cnt = bit.query(mmax - i);
        if (cnt >= i) ans = max(ans, i);
    }
    return ans;
}

int main() {
    int n;
    vector<int> citations;
    while (cin >> n) citations.push_back(n);
    cout << hIndex(citations) << endl;
    return 0;
}
