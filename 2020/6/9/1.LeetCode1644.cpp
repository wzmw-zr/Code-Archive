/*************************************************************************
	> File Name: 1.LeetCode1644.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月09日 星期二 07时04分56秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


int translateNum(int num) {
    string s;
    int ret[40] = {0};
    while (num) {
        s += num % 10 + '0';
        num /= 10;
    }
    ret[0] = ret[1] = 1;
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        s[i] ^= s[j], s[j] ^= s[i], s[i] ^= s[j];
    }
    for (int i = 2; i <= s.size(); i++) {
        if (s[i - 2] == '0') {
            ret[i] = ret[i - 1];
            continue;
        }
        int tmp = s[i - 1] - '0' + (s[i - 2] - '0') * 10;
        if (tmp > 25) ret[i] = ret[i - 1];
        else ret[i] = ret[i - 1] + ret[i - 2];
    }
    return ret[s.size()];
}


int main() {
    int num;
    cin >> num;
    cout << translateNum(num) << endl;
    return 0;
}
