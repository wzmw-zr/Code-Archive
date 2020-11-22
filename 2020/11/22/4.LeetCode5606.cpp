/*************************************************************************
	> File Name: 4.LeetCode5606.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月22日 星期日 10时35分17秒
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

string getSmallestString(int n, int k) {
    unordered_map<int, char> mp;
    string ans = "";
    for (int c = 'a', i = 1; i <= 26; c++, i++) mp[i] = c;
    while (n) {
        if ((n - 1) * 26 >= k) {
            ans += "a";
            n--;
            k--;
        } else {
            ans += mp[k - (n - 1) * 26];
            k = (n - 1) * 26;
            n--;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << getSmallestString(n, k) << endl;
    return 0;
}
