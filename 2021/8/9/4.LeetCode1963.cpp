/*************************************************************************
	> File Name: 4.LeetCode1963.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月09日 星期一 21时26分13秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int minSwaps(string s) {
    stack<char> st;
    for (char c : s) {
        if (st.empty() || c == '[') {
            st.push(c);
        } else {
            if (st.top() == '[') st.pop();
            else st.push(c);
        }
    }
    int cnt = st.size() / 2;
    return cnt / 2 + cnt % 2;
}

int main() {
    return 0;
}
