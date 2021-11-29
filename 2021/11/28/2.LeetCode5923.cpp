/*************************************************************************
	> File Name: 2.LeetCode5923.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年11月28日 星期日 08时54分34秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

int minimumBuckets(string street) {
    int n = street.size();
    vector<int> check(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (street[0] == '.') continue;
            if (n == 1 || street[1] == 'H') return -1;
            check[1] = 1;
            ans++;
        } else if (i == n - 1) {
            if (street[n - 1] == '.') continue;
            if (street[n - 2] == 'H') return -1;
            if (!check[n - 2]) ans++;
            check[n - 2]++;
        } else {
            if (street[i] == '.') continue;
            if (street[i - 1] == 'H' && street[i + 1] == 'H') return -1;
            if (street[i - 1] == '.' && check[i - 1]) {
                check[i - 1]++;
                continue;
            }
            if (street[i - 1] == '.' && street[i + 1] == 'H') {
                check[i - 1]++;
                ans++;
                continue;
            }
            check[i + 1]++;
            ans++;
        }
    }
    return ans;
}

int main() {
    string street;
    cin >> street;
    cout << minimumBuckets(street) << endl;
    return 0;
}
