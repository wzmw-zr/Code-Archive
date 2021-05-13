/*************************************************************************
	> File Name: 1.LeetCode12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月14日 星期五 00时03分20秒
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

string intToRoman(int num) {
    string ans = "";
    if (num >= 1000) {
        int t = num / 1000;
        num -= t * 1000;
        for (int i = 0; i < t; i++) ans += 'M';
    } 
    if (num >= 100) {
        int t = num / 100;
        num -= t * 100;
        if (t == 9) ans += "CM";
        else if (t == 4) ans += "CD";
        else if (t >= 5) {
            t -= 5;
            ans += 'D';
            for (int i = 0; i < t; i++) ans += 'C';
        } else {
            for (int i = 0; i < t; i++) ans += 'C';
        }
    }
    if (num >= 10) {
        int t = num / 10;
        num -= t * 10;
        if (t == 9) ans += "XC"; 
        else if (t == 4) ans += "XL";
        else if (t >= 5) {
            t -= 5;
            ans += 'L';
            for (int i = 0; i < t; i++) ans += 'X';
        } else {
            for (int i = 0; i < t; i++) ans += 'X';
        }
    }
    if (num > 0) {
        if (num == 9) ans += "IX";
        else if (num == 4) ans += "IV";
        else if (num >= 5) {
            num -= 5;
            ans += 'V';
            for (int i = 0; i < num; i++) ans += 'I';
        } else {
            for (int i = 0; i < num; i++) ans += 'I';
        }
    }
    return ans;
}

int main() {
    int num;
    cin >> num;
    cout << intToRoman(num) << endl;
    return 0;
}
