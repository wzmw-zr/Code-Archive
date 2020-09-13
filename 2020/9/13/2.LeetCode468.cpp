/*************************************************************************
	> File Name: 2.LeetCode468.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月13日 星期日 09时25分45秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

bool isIPV4(vector<string> &part) {
    for (auto &x : part) {
        if (x.size() > 3) return false;
        if ((x.size() >= 2) && (x[0] == '0')) return false;
        int num = 0;
        for (auto &y : x) num = num * 10 + y - '0';
        if (num >= 256) return false;
    }
    return true;
}

bool hexCheck(char c) {
    return ((c >= '0') && (c <= '9')) || ((c >= 'a') && (c <= 'f')) || ((c >= 'A') && (c <= 'F'));
}

bool isIPV6(vector<string> &part) {
    for (auto &x : part) {
        if (x.size() > 4) return false;
        for (auto &y : x) {
            if (!hexCheck(y)) return false;
        }
    }
    return true;
}


string validIPAddress(string IP) {
    vector<string> part;
    string temp = "";
    int ind = 0, len = IP.size();
    if (IP.find('.') != string::npos) {
        while (ind < len) {
            if (IP[ind] != '.') temp += IP[ind];
            else {
                part.push_back(temp);
                temp = "";
            }
            ind++;
        }
    } else {
        while (ind < len) {
            if (IP[ind] != ':') temp += IP[ind];
            else {
                part.push_back(temp);
                temp = "";
            }
            ind++;
        }
    }
    if (temp != "") part.push_back(temp);
    if ((part.size() != 4) && (part.size() != 8)) return "Neither";
    if (part.size() == 4) {
        if (isIPV4(part)) return "IPv4";
        return "Neither";
    }
    if (isIPV6(part)) return "IPv6";
    return "Neither";
}

int main() {
    string IP;
    cin >> IP;
    cout << validIPAddress(IP) << endl;
    return 0;
}
