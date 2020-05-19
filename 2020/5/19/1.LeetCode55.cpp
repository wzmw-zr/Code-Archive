/*************************************************************************
	> File Name: 2.LeetCode55.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月19日 星期二 18时16分02秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int lengthOfLastWord(string s) {
    int len = 0, i = s.size() - 1;
    if (i == -1) return 0;
    while (i >= 0 && s[i] == ' ') i--;
    for (; i >= 0 && s[i] != ' '; i--) len++;
    return len;
}

int main() {
    string s = " ";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}
