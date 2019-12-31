/*************************************************************************
	> File Name: 6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月01日 星期日 20时38分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int a = 2, b = 3;
    int c = ++a +b;
    int d = (2 + 3);
    int n;
    scanf("%d", &n);
    if(n % 2 == 0) printf("even\n");
    else printf("odd\n");
    printf("d = %d, c = %d", d, c);
    int t, k;
    scanf("%d%d", &t, &k);
    t ^= k;
    k ^= t;
    t ^= k;
    printf("%d %d", t, k);
    return 0;
}
