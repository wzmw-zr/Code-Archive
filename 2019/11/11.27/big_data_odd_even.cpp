/*************************************************************************
	> File Name: big_data_odd_even.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 23时55分15秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main () {
    char s[10001];
    scanf("%s", s);
    int length = strlen(s);
    if((s[length - 1] - '0') % 2 == 0) printf("YES");
    else printf("NO");
    return 0;
}
