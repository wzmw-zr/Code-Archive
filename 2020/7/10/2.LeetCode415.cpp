/*************************************************************************
	> File Name: 2.LeetCode415.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月10日 星期五 00时25分30秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string addTwoStrings(string &num1, string &num2) {
    int len_1 = num1.size(), len_2 = num2.size();
    for (auto &x : num1) x -= '0';
    for (auto &x : num2) x -= '0';
    string res(len_1 + 2, 0);
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for (int i = 0; i < len_2; i++) {
        res[i] += num1[i] + num2[i];
        if (res[i] >= 10) {
            res[i] %= 10;
            res[i + 1]++;
        }
    }
    for (int i = len_2; i < len_1; i++) {
        res[i] += num1[i];
        if (res[i] >= 10) {
            res[i] %= 10;
            res[i + 1]++;
        }
    }
    while (res.size() > 1 && res[res.size() - 1] == 0) res.replace(res.size() - 1, 1, "");
    for (auto &x : res) x += '0';
    reverse(res.begin(), res.end());
    return res;
}

string addStrings(string num1, string num2) {
    int len_1 = num1.size(), len_2 = num2.size();
    if (len_1 >= len_2) return addTwoStrings(num1, num2);
    return addTwoStrings(num2, num1);
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    cout << addStrings(num1, num2) << endl;
    return 0;
}
