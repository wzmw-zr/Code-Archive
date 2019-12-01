/*************************************************************************
	> File Name: stone_sicissors.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月01日 星期日 14时27分04秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main() {
    char l_1, r_1, l_2, r_2;
    scanf("%c %c\n%c %c", &l_1, &r_1, &l_2, &r_2);

    if ((l_1 == 'Y' && l_2 == 'H') || (l_1 == 'O' && l_2 == 'Y') || (l_1 == 'H' && l_2 == 'O')){
        if ((l_1 == 'Y' && r_2 == 'H') || (l_1 == 'O' && r_2 == 'Y') || (l_1 == 'H' && r_2 == 'O')) {
            printf("MING");
            return 0;
        }else if ((r_1 == 'Y' && r_2 == 'H') || (r_1 == 'O' && r_2 == 'Y') || (r_1 == 'H' && r_2 == 'O')) {
            printf("MING");
            return 0;
        }
        else if ((r_1 == 'Y' && r_2 == 'O') || (r_1 == 'O' && r_2 == 'H') || (r_1 == 'H' && r_2 == 'Y') || (r_1 == r_2)) {
            printf("LIHUA");
            return 0;
        }
    }
    
    if (l_1 == l_2) {
        if((r_1 == 'Y' && r_2 == 'H') || (r_1 == 'O' && r_2 == 'Y') || (r_1 == 'H' && r_2 == 'O')) {
            printf("MING");
            return 0;
        }
        else if (r_1 == r_2) {
            printf("TIE");
            return 0;
        }
        else {
            printf("LIHUA");
            return 0;
        }
    }

    if ((l_1 == 'Y' && l_2 == 'O') || (l_1 == 'H' && l_2 == 'Y') || (l_1 == 'O' && l_2 == 'Y')) {
        if((r_1 == 'Y' && l_2 == 'O') || (r_1 == 'O' && l_2 == 'H') || (r_1 == 'H' && l_2 == 'Y') || (r_1 == l_2)) printf("LIHUA");
        else if ((r_1 == 'Y' && r_2 == 'H') || (r_1 == 'O' && l_2 == 'Y') || (r_1 == 'H' && r_2 == 'O') || (r_1 == r_2)) printf("MING");
        else printf("LIHUA");
    }
    return 0;
}
