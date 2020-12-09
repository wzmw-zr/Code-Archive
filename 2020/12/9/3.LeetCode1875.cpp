/*************************************************************************
	> File Name: 3.LeetCode1875.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月09日 星期三 10时24分05秒
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

int getKthMagicNumber(int k) {
    long ans;
    priority_queue<long, vector<long>, greater<long>> que;
    unordered_set<long> st;
    que.push(1);
    st.insert(1);
    while (k--) {
        ans = que.top();
        que.pop();
        if (ans * 3 > INT32_MAX) continue;
        if (!st.count(ans * 3)) {
            st.insert(ans * 3);
            que.push(ans * 3);
        }
        if (ans * 5 > INT32_MAX) continue;
        if (!st.count(ans * 5)) {
            st.insert(ans * 5);    
            que.push(ans * 5);
        }
        if (ans * 7 > INT32_MAX) continue;
        if (!st.count(ans * 7)) {
            st.insert(ans * 7);
            que.push(ans * 7);
        }
    }
    return (int) ans;
}

int main() {
    int k;
    cin >> k;
    cout << getKthMagicNumber(k) << endl;
    return 0;
}
