/*************************************************************************
	> File Name: 1.LeetCode97.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月18日 星期六 00时07分00秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    #if 0
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    #endif

    int l1 = 0, l2 = 0, r1 = s1.size(), r2 = s2.size();
    if (r1 + r2 != s3.size()) return false;
    int ind = 0;
    while (l1 < r1 && l2 < r2) {
        #if 0
        cout << ind << " " << l1 << " " << l2 << endl;
        cout << s3[ind] << " " << s1[l1] << " " << s2[l2] << endl;
        #endif
        if (s3[ind] == s1[l1] && s3[ind] == s2[l2]) {
            return 
            isInterleave(
                s1.substr(l1 + 1, s1.size() - l1 - 1), 
                s2.substr(l2, s2.size() - l2),
                s3.substr(ind + 1, s3.size() - ind - 1)
            ) ||
            isInterleave(
                s1.substr(l1, s1.size() - l1), 
                s2.substr(l2 + 1, s2.size() - l2 - 1),
                s3.substr(ind + 1, s3.size() - ind - 1)
            );
        } else if (s3[ind] == s1[l1]) {
            ind++, l1++;
        } else if (s3[ind] == s2[l2]) {
            ind++, l2++;
        } else return false;
    }
    while (l1 < r1) {
        if (s3[ind] == s1[l1]) ind++, l1++;
        else return false;
    }

    while (l2 < r2) {
        if (s3[ind] == s2[l2]) ind++, l2++;
        else return false;
    }

    return true;
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << (isInterleave(s1, s2, s3) ? "True" : "False") << endl;
    return 0;
}
