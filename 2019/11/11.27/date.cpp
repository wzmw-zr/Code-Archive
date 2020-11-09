/*************************************************************************
	> File Name: date.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 20时12分42秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int x, y, m, d;
    scanf("%d%d%d%d", &x, &y, &m, &d);
    while(x > 0) {
        x--;
        switch (m) {
            case 1:
            if (d == 31) {
                m++;
                d = 1;
            }
            else d++;
            break;

            case 2:
            if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
                if (d == 29) {
                    m++;
                    d = 1;
                }else d++;
                break;
            }else {
                if (d == 28) {
                    m++;
                    d = 1;
                }else d++;
                break;
            }

            case 3:
            if (d == 31) {
                m++;
                d = 1;
            }
            else d++;
            break;
           
            case 4:
            if (d == 30) {
                m++;
                d = 1;
            }
            else d++;
            break;

            case 5:
            if (d == 31) {
                m++;
                d = 1;
            }
            else d++;
            break;

            case 6:
            if (d == 30) {
                m++;
                d = 1;
            }
            else d++;
            break;
            
            case 7:
            if (d == 31) {
                m++;
                d = 1;
            }
            else d++;
            break;
            
            case 8:
            if (d == 31) {
                m++;
                d = 1;
            }
            else d++;
            break;
            
            case 9:
            if (d == 30) {
                m++;
                d = 1;
            }
            else d++;
            break;
            
            case 10:
            if (d == 31) {
                m++;
                d = 1;
            }
            else d++;
            break;

            case 11:
            if (d == 30) {
                m++;
                d = 1;
            }
            else d++;
            break;
            
            case 12:
            if (d == 31) {
                y++;
                m = 1;
                d = 1;
            }
            else d++;
            break;
       }   
    }
    printf("%d %d %d", y, m, d);
    return 0;
}
