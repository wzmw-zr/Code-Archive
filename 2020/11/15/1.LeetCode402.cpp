/*************************************************************************
	> File Name: 1.LeetCode402.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月15日 星期日 00时09分39秒
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

string removeKdigits(string num, int k) {
    stack<char> st;
    int ind = 0, n = num.size();
    while ((ind < n) && k) {
        if (st.empty()) st.push(num[ind]);
        else {
            if (st.top() <= num[ind]) st.push(num[ind]); 
            else {
                while (k && !st.empty() && st.top() > num[ind]) {
                    st.pop();
                    k--;
                }
                st.push(num[ind]);
            } 
        }
        ind++;
    }
    while (ind < n) st.push(num[ind++]);
    while (k) {
        st.pop();
        k--;
    }
    string ans = "";
    while (!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }
    ans = "0" + ans;
    while (ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
    return ans;
}

int main() {
    int k;
    string num;
    cin >> num >> k;
    cout << removeKdigits(num, k) << endl;
    return 0;
}
