/*************************************************************************
	> File Name: 1.os.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月12日 星期日 00时07分55秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int status;
    pid_t child = fork();
    if (child == 0) {
        int fd = open("file.txt", RDWR, S_IRWUSR);
    } else {
        wait(&status);
        if (status != 0) {
            printf("Child failed!\n");
            return -1;
        }
    }
    char* to_write = "How dare you read my code!";
    int write_length = strlen(to_write);
    /*Part 2*/
    return 0;
}
