/*************************************************************************
	> File Name: 3.LeetCode5701.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月14日 星期日 10时31分25秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

bool areAlmostEqual(string s1, string s2) {
    int diff_cnt = 0;
    for (int i = 0; s1[i]; i++) diff_cnt += s1[i] == s2[i] ? 0 : 1;
    if (diff_cnt == 0) return true;
    if (diff_cnt == 1 || diff_cnt > 2) return false;
    int ind1 = 0, ind2 = 0, flag = 0;
    for (int i = 0; s1[i]; i++) {
        if (s1[i] == s2[i]) continue;
        if (!flag) ind1 = i, flag = 1;
        else ind2 = i;
    }
    if (s1[ind1] == s2[ind2] && s1[ind2] == s2[ind1]) return true;
    return false;
}

int main() {
    return 0;
}
