/*************************************************************************
	> File Name: 2.LeetCode1940.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月28日 星期日 00时11分31秒
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

int reverseBits(int num) {
    int l = 0, r = 0, cnt = 0, ans = 0;
    while (r < 32) {
        if (num & (1 << r)) r++;
        else {
            if (!cnt) cnt++;
            else {
                ans = max(ans, r - l);
                while (num & (1 << l)) l++;
                l++;
            }
            r++;
        }
    }
    ans = max(ans, r - l);
    return ans;
}

int main() {
    int num;
    cin >> num;
    cout << reverseBits(num) << endl;
    return 0;
}
