/*************************************************************************
	> File Name: 1.LeetCode461.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月27日 星期四 00时03分22秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int hammingDistance(int x, int y) {
    int ans = 0;
    for (int i = 0; i < 32; i++, x >>= 1, y >>= 1) {
        if ((x & 1) == (y & 1)) continue;
        ans++;
    }
    return ans;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << hammingDistance(x, y) << endl;
    return 0;
}
