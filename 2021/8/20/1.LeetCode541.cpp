/*************************************************************************
	> File Name: 1.LeetCode541.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月20日 星期五 10时45分34秒
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

string reverseStr(string s, int k) {
    int n = s.size();
    int ind = 0;
    while (ind < n) {
        for (int i = ind, j = min(ind + k - 1, n - 1); i < j; i++, j--) 
            swap(s[i], s[j]);
        ind += 2 * k;
    }
    return s;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << reverseStr(s, k) << endl;
    return 0;
}
