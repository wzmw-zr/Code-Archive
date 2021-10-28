/*************************************************************************
	> File Name: 1.LeetCode869.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月28日 星期四 08时35分09秒
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

bool reorderedPowerOf2(int n) {
    unordered_set<string> st;
    for (int i = 0; i <= 30; i++) {
        string t = to_string((1 << i));
        sort(t.begin(), t.end());
        st.insert(t);
    }
    string s = to_string(n);
    sort(s.begin(), s.end());
    return st.count(s);
}

int main() {
    int n;
    cin >> n;
    cout << ((reorderedPowerOf2(n)) ? "Yes" : "False") << endl;
    return 0;
}
