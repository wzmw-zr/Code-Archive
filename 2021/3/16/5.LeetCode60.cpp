/*************************************************************************
	> File Name: 5.LeetCode60.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月16日 星期二 17时52分45秒
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

string getPermutation(int n, int k) {
    vector<int> cnt(n, 1);
    for (int i = 1; i < n; i++) cnt[i] = cnt[i - 1] * i;
    string ans(n, ' ');
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = n - 1; i >= 0; i--) {
        int m = (k - 1) / cnt[i];
        k -= m * cnt[i];
        auto iter = st.begin();
        while (m--)  iter++;
        ans[n - 1 - i] = *iter + '0';
        st.erase(iter);
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << getPermutation(n, k) << endl;
    return 0;
}

