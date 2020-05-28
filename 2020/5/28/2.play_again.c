/*************************************************************************
	> File Name: 2.play_again.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月28日 星期四 20时00分21秒
 ************************************************************************/

#include<stdio.h>
#define Q "Do you want another try?"

int getresponce() {
    printf(Q);
    printf("(y/n)? : ");
    switch (getchar()) {
        case 'y' : 
        case 'Y' : return 1;
        case 'n' : 
        case 'N' : return 0;
        default : return -1;
    }
    return -1;
}

int main() {
    int response;
    response = getresponce();
    return response;
}
