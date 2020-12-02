/*************************************************************************
	> File Name: 2.leetCode1869.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月01日 星期二 14时02分50秒
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
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> que;
    que.push(1);
    int ans = 0;
    while (k) {
        int temp = que.top();
        que.pop();
        k--;
        ans = temp;
        if (!st.count(temp * 3)) {
            que.push(temp * 3);
            st.insert(temp * 3);
        }
        if (!st.count(temp * 5)) {
            que.push(temp * 5);
            st.insert(temp * 5);
        }
        if (!st.count(temp * 7)) {
            que.push(temp * 7);
            st.insert(temp * 7);
        }
    }
    return ans;
}

int main() {
    int k;
    cin >> k;
    cout << getKthMagicNumber(k) << endl;
    return 0;
}
