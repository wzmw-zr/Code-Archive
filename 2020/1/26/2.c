/*************************************************************************
	> File Name: 2.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月26日 星期日 22时07分58秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#define max_n 1000

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i] == 0) prime[++prime[0]] = i;
        for (int j = 1; j <= i && i * prime[j] <= max_n; j++) {
            if (i % prime[j] == 0) break;
            prime[i * prime[j]] = 1;
        }
    }
}

int main() {
    init();
    int pid = fork();
    if (pid != 0) {
        int result, status;
        result = wait(&status);
        if (result != -1 && status == 0) printf("%d\n", prime[1]);
        else printf("subprocess wrong, the exit number is %d\n", status);
    }
    else {
        printf("%d\n", prime[2]);
        exit(0);
    }
    return 0;
}
