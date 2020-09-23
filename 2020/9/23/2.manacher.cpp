/*************************************************************************
	> File Name: 2.manacher.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月23日 星期三 08时58分44秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int main() {
    string temp;
    getline(cin, temp);
    string s = "";
    for (int i = 0; temp[i]; i++) s += "#", s += temp[i];
    s += "#";
    cout << s << endl;
    int n = s.size();
    vector<int> d1(n);
    int ans = 0;
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k--;
        if (i + k > r) l = i - k, r = i + k;
        ans = max(ans, d1[i] - 1);
    }
    cout << "Longest palindrome length : " << ans << endl;
    return 0;
}
