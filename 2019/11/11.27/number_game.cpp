/*************************************************************************
	> File Name: number_game.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月27日 星期三 23时12分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main () {
    int a, b, flag = 0, pre = 0, count = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (i % 6 == 0) {
            int c = i / 100;
            for (int j = 2; j <= c / 2; j++) {
                if (c % j == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                flag = 0;
                continue;
            }
            else {
                int d = i % 100;
                for (int k = 1; k <= 10; k++) {
                    if (k * k == d) {
                        if (pre == 0){
                            pre = i;
                            count++;
                        }
                        else{
                            printf("%d ", pre);
                            pre = i;
                            count++;
                        }
                    }
                }
            }
        }
    }
    if (pre != 0) printf("%d\n", pre);
    else printf("0\n");
    printf("%d", count);
    return 0;
}
