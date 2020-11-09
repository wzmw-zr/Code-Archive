/*************************************************************************
	> File Name: 8.HOJ210.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2019年12月27日 星期五 00时40分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<inttypes.h>
#include<stdarg.h>
#include<algorithm>
#define max_n 26
using namespace std;


typedef struct word {
    int n;
    char s[max_n + 5][15];
} Word;

Word w;

int cmp(char *a, char *b) {
    if (strcmp(a, b) >= 0) return 0;
    else return 1;
}

void sort_word(char *s, int n) {
    
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", w.s[i]);
    for (int i = 1; i <= n; i++) printf("%s\n", w.s[i]);
    sort_word(w.s, n);
    //sort(w.s + 1, w.s + n + 1, cmp);
    //for (int i = 1; i <= n; i++) {
      //  i != n && cout << w.s[i] << " ";
       // i == n && cout << w.s[i];
   // }
    return 0;
}
