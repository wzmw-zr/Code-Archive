/*************************************************************************
	> File Name: 3.LeetCode5617.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月06日 星期日 10时30分42秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string interpret(string command) {
    string ans = "";
    for (int i = 0; command[i]; ) {
        if (command[i] == 'G') {
            ans += "G";
            i++;
        }
        else {
            if (command[i + 1] == ')') {
                ans += "o";
                i += 2;
            } else {
                ans += "al";
                i += 4;
            }
        }
    }
    return ans;
}

int main() {
    string command;
    cin >> command;
    cout << interpret(command) << endl;
    return 0;
}
