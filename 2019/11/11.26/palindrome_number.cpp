/*************************************************************************
	> File Name: palindrome_number.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月26日 星期二 22时19分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    string a;
    cin >> a;
    int length_a = a.length();
    int start = 0, end = length_a - 1;
    while (start < end) {
        if (a[start] != a[end]){
            cout << "NO";
            return 0;
        }
        start++;
        end--;
    }
    cout << "YES";
    return 0;
}
