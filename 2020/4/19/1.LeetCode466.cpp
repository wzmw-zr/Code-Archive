/*************************************************************************
	> File Name: 1.LeetCode466.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月19日 星期日 10时05分50秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int len1 = s1.size(), len2 = s2.size(), cnt = 0, ind = 0, ret = 0;
    int check[len1 + 5][len2 + 5];
    memset(check, 0, sizeof(check));
    int num[n1 + 5];
    memset(num, 0, sizeof(num));
    int i, j, flag = 0, tag = 0;
    int res = 0, re_start = 0, circle_len = 0;
    for (i = 1; i <= n1; i++) {
        for (j = 0; j < len1; j++) {
            if (s1[j] == s2[ind]) {
                if (!tag && !ind) {
                    tag = 1;
                    re_start = j;
                } else if (tag && !ind && j == re_start) {
                    flag = 1;
                    circle_len = i - 1;
                    break;
                } 
                /*cout << s1[j] << " ";
                cout << j << "  " << ind << endl;
                cout << "check[j][ind] = " << check[i][ind] << endl;
                */
                /*if (check[j][ind]) {
                    flag = 1;
                    break;
                }
                */
                check[j][ind] = 1;
                ind++;
            }
            if (ind == len2) {
                cnt++;
                ind = 0;
            }
        }
        if (flag) break;
        num[i] = cnt;
    }
    cout << "cnt = " << cnt << " i = " << i << " n1 = " << n1 << " flag = " << flag << " circle_len = " << circle_len << endl;
    if (flag) {
        res = ((n1 - 1) / (i - 1)) * cnt;
        int last = (n1 - 1) % (i - 1);
        res += num[last];
        /*if (!re_start) res = (n1 / (i - 1)) * cnt;
        else {
            res = ((n1 - 1) / (i - 1)) * cnt;
        }
        if (i == 2 && re_start) res += num[1];
        else {
            int last;
            ind = 0;
            if (!re_start) last = n1 % (i - 1);
            else last = (n1 - 1) % (i - 1) + 1;
            for (int i = 1; i <= last; i++) {
                for (int j = 0; j < len1; j++) {
                    if (s1[j] == s2[ind]) ind++;
                    if (ind == len2) {
                        ind = 0;
                        res++;
                    }
                }
            }
            
            //cout << "last = " << last << endl;
            res += num[last];
        } 
        */
    } else res = cnt;
    //cout << "res = " << res << endl;
    ret = res / n2;
    return ret;
}

int main() {
    int n1, n2, res;
    string s1, s2;
    cin >> s1 >> n1 >> s2 >> n2;
    res = getMaxRepetitions(s1, n1, s2, n2);
    cout << res << endl;
    return 0;
}
