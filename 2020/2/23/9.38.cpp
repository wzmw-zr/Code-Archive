/*************************************************************************
	> File Name: 9.38.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月23日 星期日 21时07分35秒
 ************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * countAndSay(int n){
    char *str = (char *) calloc(sizeof(char), 100);
    str[0] = '1';
    while (--n) {
        char c, *s = (char *) calloc(sizeof(char), strlen(str) * 2);
        int cnt = 0, ind = 0;
        for (int i = 0; str[i]; i++) {
            if (!i) {
                c = str[i];
                cnt++;
            } else {
                if (str[i] == c) {
                    cnt++;
                } else {
                    s[ind++] = cnt + '0'; 
                    s[ind++] = c;
                    c = str[i];
                    cnt = 1;
                }
            }
        }
        s[ind++] = cnt + '0';
        s[ind++] = c;
        free(str);
        str = s;
    }
    return str;
}

int main() {
    int n;
    scanf("%d", &n);
    char *ret = countAndSay(n);
    printf("%s\n", ret);
    return 0;
}
