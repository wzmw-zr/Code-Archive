/*************************************************************************
	> File Name: 1.LeetCode166.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年10月03日 星期日 10时09分47秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    if ((1L * numerator) % (1L * denominator) == 0) return to_string(1L * numerator / denominator);
    long num = abs(1L * numerator);
    long deno = abs(1L * denominator);
    string pre = "";
    if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) pre += "-";
    pre += to_string(num / deno) + ".";
    string temp = "";
    num %= deno;
    unordered_map<long, int> mp;
    int ind = 0;
    while (num && !mp.count(num)) {
        mp[num] = ind;
        ind++;
        num *= 10;
        temp += '0' + num / deno;
        num %= deno;
    }
    string ans = "";
    if (num) {
        string s = "";
        for (int i = 0; i < mp[num]; i++) s += temp[i];
        s += "(";
        for (int i = mp[num]; temp[i]; i++) s += temp[i];
        s += ")";
        ans = pre + s;
    } else ans = pre + temp;
    return ans;
}

int main() {
    int numerator, denominator;
    cin >> numerator >> denominator;
    cout << fractionToDecimal(numerator, denominator) << endl;
    return 0;
}
