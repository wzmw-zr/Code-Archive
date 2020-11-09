#include <stdio.h>
#include<string.h>

int main () {
    int n;
    scanf("%d", &n);
    printf("%d", (n % 10) * 10 + (n / 10));
    return 0;
}